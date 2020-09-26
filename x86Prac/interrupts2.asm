org 100h

; This exercise demonstrates how one could create their own interrupt.
        
push ds       
mov ax, 0
mov ds, ax
mov [0x00], handle_int0 ; So, remember, we are no longer just being concerned about the code, but also the addresses.
                        ; handle_int0 label, in reality of things, is an address.
mov [0x02], cs ; So, from 0x00 to 0x02, I have 0700:0114 (the last four always changes to something always during each new run time).
pop ds ; Get my original value for ds register back.

int 0x00 ; Since, handle_int0 is living in 0x00, I can execute my own custom interrupt.
       
ret

handle_int0:
    mov ah, 0eh
    mov al, 'A'
    int 0x10
    iret ; To return from an interrupt, we have to use an iret.