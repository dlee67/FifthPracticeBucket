### For installing i386-elf-binutils <br/>

https://stackoverflow.com/questions/40655204/cant-brew-install-gcci386-elf-gcc <br/>
https://forum.osdev.org/viewtopic.php?f=1&t=33517 <br/><br/>

Requires brew (linux has their own brew called linux brew).

# Currently following tutorials like:
https://github.com/cfenollosa/os-tutorial/tree/master/02-bootsector-print
https://wiki.osdev.org/Tutorials


# Basic Input/Output Software (BIOS)
BIOS doesn't even know if my computer even has a harddisk; so,
general practice is that programmers implment this thing called bootsector,
where the last two bytes of the bootsector is set to; 0xaa55.