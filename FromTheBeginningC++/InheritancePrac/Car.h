#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>

using namespace std;

// Derived class
class Car: public Vehicle {
  public:
    string model = "Mustang";
};

#endif