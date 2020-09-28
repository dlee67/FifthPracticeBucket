    global _my_asm ; Without the global label, C wouldn't know what to look for.
    section .text
_my_asm:
    mov eax, 10
    pop ebp
    ret