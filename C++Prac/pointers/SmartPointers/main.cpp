#include <iostream>
#include <memory>

using namespace std;

int main() {
    const int ARR_SIZE = 5;

    // Using smart pointers gets rid of the need for managing memories.
    unique_ptr<double> myDubPtr = make_unique<double>();
    // https://stackoverflow.com/questions/7576953/c-auto-keyword-why-is-it-magic
    // auto keyword decuces from what's being initialized.
    auto myArray = make_unique<int[]>(ARR_SIZE);

    *myDubPtr = 3.14;
    cout << "pointer value: " << *myDubPtr << endl;

    // Because the unique_pointers have the ownership of whatever that they are pointing,
    // so, you won't be able to assign something new to'em unless you use move().
    // unique_ptr<double> otherPtr = myDubPtr; // This will actually throw an error.
    unique_ptr<double> otherPtr = move(myDubPtr);

    for (int i = 0; i < ARR_SIZE; i++) {
        myArray[i] = i * 2;
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        cout << myArray[i] << endl;
    }

    return 0;
}