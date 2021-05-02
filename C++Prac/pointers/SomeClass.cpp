#include "SomeHeader.h"
#include <iostream>

using namespace std;

SomeClass::SomeClass (int digit) {
    this->num = digit;
}

void SomeClass::setNum(int digit) {
    this->num = digit;
}

int SomeClass::getNum() {
    return this->num;
}