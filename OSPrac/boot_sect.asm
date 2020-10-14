     cli
 hang:
     jmp hang
 
     times 510-($-$$) db 0 ; https://engineersasylum.com/t/times-510-db-0-means/132/2
     db 0x55
     db 0xAA