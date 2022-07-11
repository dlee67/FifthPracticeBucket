#include <stdio.h>

void isMonday(int hours);
void isTuesday(int hours);
void isWednesday(int hours);
void isThursday(int hours);
void isFriday(int hours);

int main() {
    printf("Please input the day: \n");
    int day = 0; 
    scanf("%d", &day);
    printf("Please input the hour: \n");
    int hours = 0; 
    scanf("%d", &hours);

    if (!(day <= 7 && day >= 1)) {    
        printf("Invalid day.");
        return;
    }

    if (!(hours <= 23 && hours >= 0)) {
        printf("Invalid hours.");
        return;
    }

    switch(day) {
        case 1:
            isMonday(hours);
            break;
        case 2:
            isTuesday(hours);
            break;
        case 3:
            isWednesday(hours);
            break;
        case 4:
            isThursday(hours);
            break;
        case 5:
            isFriday(hours);
            break;

        case 6:
        case 7:
            printf("It's Saturday/Sunday. No course(s). It's the weekend.");
            return;
    }

    return 0;
} 

void isMonday(int hours) {
    if (hours >= 8 && hours < 10) {
        printf("It's Monday. You'll have a writte course at this moment.");
    } else if (hours >= 14 && hours < 16) {
        printf("It's Monday. You'll have a Math course at this moment.");
    } else {
        printf("It's Monday. You don't have any class to attend at this time.");
    }
}

void isTuesday(int hours) {
    if (hours >= 10 && hours < 12) {
        printf("It's Tuesday. You'll have a Chemistry course at this moment.");
    } else if (hours >= 16 && hours < 18) {
        printf("It's Tuesday. You'll have a Soccer course at this moment.");
    } else {
        printf("It's Tuesday. You don't have any class to attend at this time.");
    }
}

void isWednesday (int hours) {
    if (hours >= 14 && hours < 16) {
        printf("It's Wednesday. You'll have a Math course at this moment.");
    } else {
        printf("It's Wednesday. You don't have any class to attend at this time.");
    }
}

void isThursday (int hours) {
    if (hours >= 10 && hours < 12) {
        printf("It's Thursday. You'll have a Chemistry course at this moment.");
    } else if (hours >= 16 && hours < 18) {
        printf("It's Thursday. You'll have a Swim course at this moment.");
    } else {
        printf("It's Thursday. You don't have any class to attend at this time.");
    }
}

void isFriday (int hours) {
    if (hours >= 10 && hours < 12) {
        printf("It's Friday. You'll have a Chinese course at this moment.");
    } else if (hours >= 16 && hours < 18) {
        printf("It's Friday. You'll have a Basketball course at this moment.");
    } else {
        printf("It's Friday. You don't have any class to attend at this time.");
    }
}