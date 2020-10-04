    global _my_asm ; Without the global label, C wouldn't know what to look for.
    extern _getchar ; This is actually a c function
    section .text
_my_asm:
    push ebp
    mov ebp, esp

    call _getchar
    ; eax = char they entered
    pop ebp
    ret