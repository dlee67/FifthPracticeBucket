#include <iostream>
#include <string>
#include "Swapper.h"

using namespace std;

template <class T> 
T getBigger(T a, T b);

double getBigger(double a, double b);
int getBigger(int a, int b);
string getBigger(string a, string b);

int main() {
    Swapper<int> intSwapper(5, 10);
    Swapper<string> stringSwapper("John", "Bob");

    cout << intSwapper.getFirst() << endl;
    cout << stringSwapper.getFirst() << endl;

    return 0;
}