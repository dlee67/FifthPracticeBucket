#ifndef MYPAIR_H // There is apparently something called #pragma once, and that does the same thing here.
#define MYPAIR_H

template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

#endif