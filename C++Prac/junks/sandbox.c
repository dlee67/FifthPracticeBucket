#include <stdio.h>

int main() {
    int a = 10, b = 4, res;
    float c = 3.0;
    printf("a is %d and b is %d and c is %f\n", a, b, c);

    res = a + b;
    printf("a+b is %d\n", res);

    res = a - b;
    printf("a-b is %d\n", res);

    res = a * b;
    printf("a*b is %d\n", res);

    res = a / b;
    printf("a/b is %d\n", res);

    res = a % b;
    printf("a%%b is %d\n", res);

    printf("integer specifier: a/c is %d\n", a/c);
    printf("float specifier: a/c is %f\n", a/c);
    printf("integer specifier: 1+ a/c *2.0 is %d \n", 1+a/c*2.0);
    printf("float specifier: 1+ a/c *2.0 is %f \n", 1+a/c*2.0);
    printf("integer specifier: 1+ a/b *2.0 is %d \n", 1+a/b*2.0);
    printf("float specifier: 1+ a/b *2.0 is %f \n", 1+a/b*2.0);

    return 0;
} 