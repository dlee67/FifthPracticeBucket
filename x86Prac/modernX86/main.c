#include <stdio.h>
extern int my_asm();
// All the exported functions start with an underscore
int main(int argc, char** argv) {
    int r = my_asm();
    printf("Value: %i\n", r);
    return 0;
}