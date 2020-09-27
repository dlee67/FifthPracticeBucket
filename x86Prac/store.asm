org 100h

mov al, 'A'
mov di, message
stosb ; Remember store vs load? Where store instruction stores values to memory and load instruction loads values from memory to registers?
      ; Instead of using SI register, store instruction uses di register.
               
ret       

message: db 'Hello world!', 0 ; db stands for data byte. The zero at the end is literally a value zero (null terminator), this is important for lodsb.                                    