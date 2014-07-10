BASEURL=http://ipxe.example.com
# ============================================================================
# Desired end results:
#
# See http://etherboot.org/wiki/romburning/vbox
# Default for Most Guest VM OS Choices
all:: 10222000.rom 
# Intel PRO/1000 MT Desktop (82540EM) Default for Windows Vista/Windows 7 VMs
all:: 8086100e.rom 

# The full featured 'second stage' version that doesn't fit into the ROM
all:: menuloader.pxe

# ============================================================================

ipxe-full:
	@echo Downloading the iPXE sources
	git clone git://git.ipxe.org/ipxe.git $@
	-@rm -f ipxe-full/src/config/local/general.h
	-@rm -f ipxe-full/src/config/local/console.h

ipxe-full/src/config/local/general.h: general-full.h ipxe-full
	cp $< $@

ipxe-full/src/config/local/console.h: console-full.h ipxe-full
	cp $< $@

clean::
	-@[ -d ipxe-full ] && cd ipxe-full/src && make clean	
	-@rm -f ipxe-full/src/config/local/general.h
	-@rm -f ipxe-rom/src/config/local/console.h

ipxe-rom: ipxe-full
	@echo Downloading the iPXE sources
	@cp -a $< $@
	-@rm -f ipxe-rom/src/config/local/general.h

clean::
	-@[ -d ipxe-rom ] && cd ipxe-rom/src && make clean	

ipxe-rom/src/config/local/general.h: general-rom.h ipxe-rom
	cp $< $@

clean::
	-@rm -f ipxe-rom/src/config/local/general.h

.PRECIOUS:script-%.ipxe

script-%.ipxe:script-%.ipxe.in Makefile
	cat $< | sed 's@##BASEURL##@${BASEURL}@g' > $@

clean::
	-@rm -f script-*.ipxe

%.rom: script-rom.ipxe ipxe-rom Makefile ipxe-rom/src/config/local/general.h 
	@echo Building $@
	@( \
	  cd ipxe-rom/src ;\
	  make -j4 bin/$@ EMBED=../../$< ;\
	  cp bin/$@ ../..;\
	)
	@( \
	  if [ $$(wc -c "$@" | cut -f 1 -d ' ') -gt 57344 ] ; \
	  then \
	    echo "The size of the ROM is larger than 0xE000 (=57344) bytes and so it WILL NOT LOAD" ; \
		exit -1;\
	  else \
	    echo "The $@ ROM fits." ; \
	  fi \
	)

clean::
	rm -f *.rom *.iso

menuloader.pxe: script-full.ipxe ipxe-full Makefile ipxe-full/src/config/local/general.h ipxe-full/src/config/local/console.h
	@echo Building $@
	@( \
	  cd ipxe-full/src ;\
	  make -j4 bin/ipxe.pxe EMBED=../../$< ;\
	  cp bin/ipxe.pxe ../../$@;\
	)

clean::
	rm -f menuloader.pxe
