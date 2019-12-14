#ifndef MYHEADER_H // There is apparently something called #pragma once, and that does the same thing here.
#define MYHEADER_H

template <class T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second);
};

#endif