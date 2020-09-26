org 100h

mov al, 10
cmp al, 10 ; compares if the al register holds the value 10. If it is equal, ZF flag is set to 1.
je _equal ; Jump if zf flag is 1.
;jne _equal ; Jump if zf flag is 0.
jmp _exit

_equal:                             
    mov ah, 0eh
    mov al, 'A'
    int 0x10
    
_exit:
    
                    
ret                                            