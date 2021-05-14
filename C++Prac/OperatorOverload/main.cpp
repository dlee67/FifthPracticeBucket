#include <iostream>
using namespace std;

class SomeClass {
   public:
      int num = 5;
      
      int operator+(SomeClass& b) {
         return this->num + b.num;
      }
};

// Main function for the program
int main() {
    SomeClass someClassOne;
    SomeClass someClassTwo;

    cout << someClassOne + someClassTwo << endl;

    return 0;
}