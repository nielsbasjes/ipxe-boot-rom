# See http://etherboot.org/wiki/romburning/vbox
# Default for Most Guest VM OS Choices
all:: 10222000.rom 
# Intel PRO/1000 MT Desktop (82540EM) Default for Windows Vista/Windows 7 VMs
all:: 8086100e.rom 

# ============================================================================

ipxe:
	@echo Downloading the iPXE sources
	git clone git://git.ipxe.org/ipxe.git

clean::
	cd ipxe/src && make clean	

ipxe/src/config/local/general.h: general.h ipxe
	cp $< $@

clean::
	rm -f ipxe/src/config/local/general.h

%.rom: romscript.ipxe ipxe Makefile ipxe/src/config/local/general.h
	@echo Building $@
	@( \
	  cd ipxe/src ;\
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
