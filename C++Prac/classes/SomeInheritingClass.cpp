#include "SomeInheritingClass.h"
#include <iostream>

using namespace std;

SomeInheritingClass::SomeInheritingClass(int digit, string name) : SomeClass(digit) {
    this->someString = name;
}

string SomeInheritingClass::getSomeString() {
    return someString;
}

void SomeInheritingClass::setSomeString(string name) {
    this->someString = name;
}