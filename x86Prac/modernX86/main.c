#include <stdio.h>

extern char my_asm();
// All the exported functions start with an underscore
int main(int argc, char** argv) {
    char c = my_asm();
    printf("%c\n", c);
    return 0;
}