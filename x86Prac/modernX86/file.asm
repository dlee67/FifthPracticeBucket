    global _main ; make _main external to other people
    extern _printf ; Pretend that we have _printf somewhere, we'll reserve it later.

    section .text
_main:
    push message ; Push the address of the message.
    call _printf
    add esp, 4 ; Takes the message address off the stack. 
    ret

message:
    db 'Hello, World', 10, 0