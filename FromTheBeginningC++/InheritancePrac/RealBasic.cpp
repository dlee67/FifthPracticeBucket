#include <iostream>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

void Vehicle::honk() {
  cout << "HONK! HONK!" << endl;
}

int main() {
  Car myCar;
  myCar.honk();
  cout << myCar.brand + " " + myCar.model << endl;
  return 0;
}