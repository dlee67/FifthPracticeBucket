#ifndef SOME_INHERITING_CLASS
#define SOME_INHERITING_CLASS

#include <string>
#include "SomeHeader.h"

using namespace std;

class SomeInheritingClass : public SomeClass 
{

    public:
        SomeInheritingClass(int digit, string someString);
        string getSomeString();
        void setSomeString(string name);

    private:
        string someString;
};

#endif