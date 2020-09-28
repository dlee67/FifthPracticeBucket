    global _my_asm ; Without the global label, C wouldn't know what to look for.
    section .text
_my_asm:
    push ebp
    mov ebp, esp

    mov eax, 777
    mov edx, 'A'
    
    pop ebp
    ret