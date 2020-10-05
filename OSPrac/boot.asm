;boot.asm
; By default, this code is loaded at address 0000:7c00
; https://www.felixcloutier.com/x86/cli
; Clears IF or the VIF flag.
; https://en.wikipedia.org/wiki/Interrupt_flag
; Meaning, cli will forbid all interrupts.
     cli
 hang:
     jmp hang
 
     times 510-($-$$) db 0 ; Fill up 512 bytes with zeroes.
     ; Unless I am using QEMU or old BIOS, I must has the below two lines because
     ; those older things looks for boot signature (0xAA55).
     db 0x55
     db 0xAA