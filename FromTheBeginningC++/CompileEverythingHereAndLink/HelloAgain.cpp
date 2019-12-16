#include <cstdio>
#include <iostream> // <> uses include directories.
#include "mypair.h" // "" marks signifise relative directories.
#include "moreclass.h"

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

int main() {
  // int i=5, j=6, k;
  // Rectangle rect;
  // MoreClass moreClass;
  // mypair<int> myObject (100, 75);
  // rect.set_values(3,4);
  // cout << "area: " << rect.area() << endl;
  // rect.sayHello();
  // rect.sayBye("Sekiro");
  // moreClass.sayClass(); 
  // cout << myObject.getmax() << endl;
  mypair <int> myobject (100, 75);
  cout << myobject.getmax();
  return 0;
}