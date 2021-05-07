#include <iostream>

using namespace std;

int main() {
    const int ARR_SIZE = 5;

    int* myArray = new int[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++) {
        myArray[i] = i * 2;
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        cout << myArray[i] << endl;
    }

    // https://www.geeksforgeeks.org/delete-in-c/
    delete[] myArray;

    return 0;
}