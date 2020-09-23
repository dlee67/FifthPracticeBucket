
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
        
; Registers AX, BX, CX, and DX has high and low bytes.        
mov ah, 0xAA
mov al, 0xBB
mov ax, 0xffff ; Ofcourse, I can just chuck in a value straight.

lodsb ; Uses the byte whatever the SI register is pointing, and loads it in to lower AX (al) register.    

ret