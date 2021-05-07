#include <iostream>
#include "SomeHeader.h"

using namespace std;

// https://www.geeksforgeeks.org/delete-in-c/
int main() {
    // There are two ways to write the blow.
    // int* intPointer = new int(42);
    int* intPointer = new int;
    *intPointer = 123;
    delete intPointer;
    intPointer = nullptr;

    SomeClass* someClass = new SomeClass(5);

    cout << (*someClass).getNum() << endl;

    delete someClass;

    someClass = nullptr;

    return 0;
}