org 100h
      
mov bx, 0xfff0 ; Trying to achieve the same affect with AX register will give me a compilation error.
               ; This is super fascinating. It's because there are, literally, no circuits on x86 chips 
               ; that allows you to do this.       
mov word [bx], 0xff

ret