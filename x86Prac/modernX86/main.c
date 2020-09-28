#include <stdio.h>
struct test 
{
    int a;
    char b;
};

extern struct test my_asm();
// All the exported functions start with an underscore
int main(int argc, char** argv) {
    struct test a = my_asm();
    printf("%i %c", a.a, a.b);
    return 0;
}