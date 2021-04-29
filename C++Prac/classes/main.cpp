#include <iostream>
#include <string>
#include "SomeHeader.h"

using namespace std;

void printSomeClassNum(SomeClass someClass);
void printWithRefernce(const SomeClass& someClass);

int main () {
    
    SomeClass someClass;
    someClass.setNum(5);

    cout << someClass.getNum() << endl;
}

// Pass by value
void printSomeClassNum(SomeClass someClass) {
    cout << "SomeClass has " << someClass.getNum() << endl;
}

// Pass by reference
void printWithRefernce(SomeClass& someClass) {
    cout << "SomeClass has " << someClass.getNum() << endl;
}