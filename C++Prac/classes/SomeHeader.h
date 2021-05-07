//The #ifndef directive checks if a macro name is not defined. The directive uses the following syntax:
#ifndef SOME_C
// Essentially, everything below the above preprocessor macro,  
#define SOME_C

#include <string>

using namespace std;

class SomeClass {
    public:
        SomeClass(int digit);

        void setNum(int digit);

        // This pure virtual function is what enables the polymorphism.
        virtual int getNum() = 0;

    private:
        int num;
}; // Classes in Cpp requires semicolon

#endif