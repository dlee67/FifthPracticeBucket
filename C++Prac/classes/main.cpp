#include <iostream>
#include <string>

#include "SomeHeader.h"
#include "SomeInheritingClass.h"

using namespace std;

void printSomeClassNum(SomeClass someClass);
void printWithRefernce(const SomeClass& someClass);

int main () {
    
    // SomeClass is now an abstract call, the below doesn't work anymore. 
    // Having even a single pure virtual function makes a class an abstract class.
    // SomeClass someClass(2);
    // someClass.setNum(5);
    // cout << someClass.getNum() << endl;

    // In order to use Polymorphism in C++, the object must be instantiated with a pointer.
    // There are two types of binding for the functions:
    // early (static) binding : when a function call is bounda to the function during the compilation time.
    // late (dynamic) binding : when a function call is bound to the function during the runtime.
    SomeClass* somePointer = new SomeInheritingClass(3, "Some string");

    cout << somePointer->getNum() << endl;

    delete somePointer;
    somePointer = nullptr;

}