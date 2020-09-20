org 100h

; This code demonstrates that call routines uses stack.

_main:                                                                                     
    call _test ; Calls _test. It also uses the stack pointer. So, SP points to FFFE, right?
               ; Soon as the call _test is ran, the computer will store 301 (return address) in 700:FFFC
    mov ah, 0x20
    ret
_test:
    mov ah, 0x10
    ret ; Returns from the subroutine and goes back to where the call _test was ran by grabbing the return address from 700:FFFC