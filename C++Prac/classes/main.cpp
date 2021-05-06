#include <iostream>
#include <string>

#include "SomeHeader.h"
#include "SomeInheritingClass.h"

using namespace std;

void printSomeClassNum(SomeClass someClass);
void printWithRefernce(const SomeClass& someClass);

int main () {
    
    SomeClass someClass(2);
    someClass.setNum(5);

    cout << someClass.getNum() << endl;

    SomeInheritingClass someInheritingClass(2, "Some string");
    someInheritingClass.setNum(5);
    someInheritingClass.setSomeString("Not some string");

    cout << someInheritingClass.getNum() << endl;
    cout << someInheritingClass.getSomeString() << endl;
}

// Pass by value
void printSomeClassNum(SomeClass someClass) {
    cout << "SomeClass has " << someClass.getNum() << endl;
}

// Pass by reference
void printWithRefernce(SomeClass& someClass) {
    cout << "SomeClass has " << someClass.getNum() << endl;
}