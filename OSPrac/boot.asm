; https://stackoverflow.com/questions/46811232/what-does-org-0x7c00-actually-do-to-the-file
[org 0x7c00]
mov ah, 0x0e

; Without the org instruction, the below code will break.
mov al, "2"
int 0x10
mov al, [the_secret]
int 0x10

jmp $ ; infinite loop

the_secret:
    ; ASCII code 0x58 ('X') is stored just before the zero-padding.
    ; On this code that is at byte 0x2d (check it out using 'xxd file.bin')
    db "X"

; zero padding and magic bios number
times 510-($-$$) db 0
dw 0xaa55