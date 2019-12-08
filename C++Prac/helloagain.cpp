#include <cstdio>
#include <iostream>
using namespace std;

struct ClockOfTheLongNow {
    
};

int main() {
    int gettysburg = 5;
    printf("The value of my_ptr is %p.\n", gettysburg);
    int *gettysburg_address = &gettysburg; // The asterisk is used for creating a pointer datatype.
    printf("&gettysburg: %p.\n", gettysburg_address);
    // Also, it is used to dereference an address data type.
    std::cout << "Value at the gettysburg adress: " << *gettysburg_address << "\n";
    // Where pointers and dereferences are two different things.
}