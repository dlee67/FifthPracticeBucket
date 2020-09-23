
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax, 0x300 ; Without this line, this code will fail.
mov ds, ax ; Data segment register is like a reference point.
mov [0xff], 0x30 ; Instead of 0x30 living in 700:ff, now it will live in 300:ff

jmp 0x7c0:0xff ; This line will literally jump to CS 0x7C0 IP 0x0FF
               ; I have to recognize that CS and the IP combined represent the address that my program counter points to.

ret