; This program briefly explains how hardware is interacted with in assembly.

org 100h
                    
mov al, 'A' ; I have an "A" 
out 130, al ; Let's assume that I have a printer seating in port 130, and the "out" instruction will enable to me 
            ; to print out whatever I have in al register.

; That's really it.

ret

                                            