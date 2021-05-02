#include <iostream>
#include <SomeHeader.h>

using namespace std;

int main() {
    // int* intPointer = new int(42);
    int* intPointer = new int;
    *intPointer = 123;
    delete intPointer;
    intPointer = nullptr;

    SomeClass* someClass = new SomeClass(5);

    return 0;
}