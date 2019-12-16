#include <iostream>
#include "mypair.h" // "" marks signifise relative directories.

using namespace std;

template <class T>
//void MyPair::comparePair(T a, T b) <- That will break things.
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}