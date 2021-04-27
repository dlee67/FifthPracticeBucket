#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> someVec;
    vector<string> anotherVec(3);

    someVec.push_back(1);
    someVec.push_back(2);
    someVec.push_back(3);

    cout << "someVec size: " << someVec.size() << endl;

    return 0;
}