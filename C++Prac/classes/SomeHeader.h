#ifndef SOME_C
#define SOME_C

#include <string>

using namespace std;

class SomeClass {
    public:
        void setNum(int digit);

        int getNum();

    private:
        int num;
}; // Classes in Cpp requires semicolon

#endif