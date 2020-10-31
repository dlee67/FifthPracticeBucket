Currently following tutorials like:
https://github.com/cfenollosa/os-tutorial/tree/master/02-bootsector-print //Tutorial 21 requires qemu-system-i386 -fda os-image.bin to run. <br/>
https://wiki.osdev.org/Tutorials

Basic Input/Output Software (BIOS)
BIOS doesn't even know if my computer even has a harddisk; so, general practice is that programmers implment this thing called bootsector, where the last two bytes of the bootsector is set to; 0xaa55.

