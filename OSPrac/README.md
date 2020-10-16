# Huge thanks to ...
https://github.com/cfenollosa/os-tutorial/tree/master/13-kernel-barebones

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

# Interrupts are a mechanism that allow the CPU temporarily to halt what it is doing and run some other, higher-priority instructions before returning to the original task.

# 16-bit realmode is the mode that CPU is in during the boot. 
What does that mean? Notice how all the tutorials I've been going through
were only using 16 bits in registers; however, after CPU
enters the "protected-mode," the registers can now use 32-bits.

When the CPU is in the real mode, I am able to use the BIOS routine to do things like print things, but
once the computer is in protected mode (32-bit), I must use my own device drivers.

# Global Descriptor Table
