#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

// Base class
class Vehicle {
  public:
    string brand = "Ford";
    void honk();
};

#endif