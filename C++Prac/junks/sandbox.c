#include <stdio.h>
#include <limits.h>

int main() {
    int a = 0; scanf("%d", &a);
    int b = 0; scanf("%d", &b);
    int c = 0; scanf("%d", &c);
    
    int i;
    int middleVal = 0;
    int quotient = 0;
    int remainder = 0;
    int largestVal = INT_MIN;
    int smallestVal = INT_MAX;
    float sum = a + b + c;
    float average = (a + b + c) / 3;
    int arry[] = {a, b, c};
    for (i = 0; i < 3; i++) {
        if (largestVal < arry[i]) {
            largestVal = arry[i];
        }
        if (smallestVal > arry[i]){
            smallestVal = arry[i];
        }
    }

    for (i = 0; i < 3; i++) {
        if (arry[i] < largestVal && arry[i] > smallestVal) {
            middleVal = arry[i];
        }
    }    

    printf("%d\n", largestVal);
    printf("%d\n", smallestVal);
    printf("%.4f\n", sum);
    printf("%.4f\n", average);
    printf("%d\n", middleVal);
    quotient = largestVal / middleVal;
    printf("%d\n", quotient);
    remainder = largestVal % middleVal;
    printf("%d\n", remainder);

    int isItOdd = middleVal % 3;
    if (isItOdd == 0 && 0 <= isItOdd) {
        sum = sum + 1;
    } else {
        sum = sum - 3;
    }
} 