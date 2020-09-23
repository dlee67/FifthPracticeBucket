org 100h
      
; For interrupts
mov ah, 0eh ; 0x0E, h is there to indicate that the value is an hexadecimal.
mov al, 'A'
int 0x00 ; int doesn't stand for int, but it actually stands for interrupt.
         ; int instruction will look at the vector table and grab the address in 0x00 
         ; which is F400:0170 (remember, x86 arranges memory in little endian).

; Lesson regarding the interrupt introduces this idea called interrupt vector table.
; Like the rest of the tables do, interrupt vector table, ofcourse, contains the addresses 
; to certain locations on the memory. In interrupt vector table's case, those addresses points to
; BIOS instruction

ret