#include <iostream>
#include "mypair.h"

using namespace std;

int main () {
  mypair<int>* myobject = new mypair<int>(100, 75);
  cout << myobject->getmax() << endl;
  return 0;
}