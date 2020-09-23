# Couple things that surprised me ...
For x86, memory is arranged in little endian.
So, if a register is moving 0x20CD into 0x000 memory address,
0x0000 will have: 0xCD20.