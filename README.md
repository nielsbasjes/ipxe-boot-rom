iPXE boot rom
=============

This is a small set of scripts that simply download and build a bootrom of iPXE that can be used as an alternative bootrom in VirtualBox.

Why?
====
I found that building a working ROM is harder than it seems.
Without any configuration the image will be too large.

So in order to make this work a LOT of features had to be disabled.
This is done by creating a set of overrules that are located in the general.h file

VirtualBox LAN boot ROM Size
==========
On this site https://gist.github.com/robinsmidsrod/4001104 it says this about the size:

    include/iprt/cdefs.h
    1888:#define _64K                    0x00010000
 
    src/VBox/Devices/PC/DevPcBios.h
    43:#define VBOX_LANBOOT_SEG            0xe200
  
    src/VBox/Devices/PC/DevPcBios.cpp
    1348:                if (cbFileLanBoot > _64K - (VBOX_LANBOOT_SEG << 4 & 0xffff))
   
    $ perl -e 'printf "%x\n", 0x10000 - 0xe200 << 4 & 0xffff'
    e000
    $ perl -e 'printf "%d\n", 0x10000 - 0xe200 << 4 & 0xffff'
    57344
  
So the conclusion is that the maximum size of a ROM is 0xE000 bytes (= 57344)

Building
========
Change the first line of the Makefile.

I run this on my CentOS system and simply type

    make   

Installing the new LAN boot ROM into VirtualBox
========
See: http://etherboot.org/wiki/romburning/vbox

8086100e.rom is the LAN boot ROM for the Intel PRO/1000 MT Desktop (82540EM) which is the default when you have the VirtualBox Extension Pack installed.

- Create a virtual machine ( Here I call it "Hadoop Client" ) and do settings that you want to boot from network
- Copy the 8086100e.rom into the directory of that VM
- Add the ROM image to the VM config:
Under Linux:  vboxmanage setextradata "Hadoop Client" VBoxInternal/Devices/pcbios/0/Config/LanBootRom 8086100e.rom
Under Windows: "c:\Program Files\Oracle\VirtualBox\VBoxManage.exe" setextradata "Hadoop Client" VBoxInternal/Devices/pcbios/0/Config/LanBootRom "C:\VirtualBox VMs\Hadoop Client\8086100e.rom" 
