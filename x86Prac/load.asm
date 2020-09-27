org 100h

mov si, message ; This will have our computer point to our message.
lodsb ; Once again, I have to recognize that I am currently programming in x86.
      ; Just like when we were coding in ARM, when trying to read a string literal, we had to 
      ; read things byte by byte.
      ; lodsb instruction will tell the computer to read the byte of whatever si register is pointing at and increments the si. 
      ; Combine with loop, that's how I can read the string literals like below.
               
ret       

message: db 'Hello world', 0 ; db stands for data byte. The zero at the end is literally a value zero, this is important for lodsb.                                    