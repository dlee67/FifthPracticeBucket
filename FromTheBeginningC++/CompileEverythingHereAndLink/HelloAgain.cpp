#include <cstdio>
#include <iostream> // <> uses include directories.
#include "myheader.h" // "" marks signifise relative directories.
#include "moreheader.h"
using namespace std;

class Rectangle {
    int width, height;
  public:
    int area() {return width*height;}
    void set_values (int,int);
    void sayBye();
    void sayBye(string personName);
    void sayHello() {
        cout << "Hello!" << endl;
    }
};

// The :: is something called scope operator.
void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

void Rectangle::sayBye () {
  cout << "Bye." << endl;
}

void Rectangle::sayBye (string personName) {
  cout << "Bye, " << personName << endl;
}

void MoreClass::sayClass () {
  cout << "CLASS!" << endl;
}

int main() {
    Rectangle rect;
    MoreClass moreClass;
    rect.set_values(3,4);
    cout << "area: " << rect.area() << endl;
    rect.sayHello();
    rect.sayBye("Sekiro");
    moreClass.sayClass(); // Is this really how people do OO in C++?
    return 0;
}