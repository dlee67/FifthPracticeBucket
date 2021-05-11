#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <vector>
//https://www.cplusplus.com/reference/algorithm/
#include <algorithm>

using namespace std;

void printDeque(deque<int> deck);

void fillVector(vector<int>& myVector);
void printVector(vector<int>& myVector);
void countFives(vector<int>& myVector);

int main() {
    deque<int> myDeck;

    myDeck.push_back(1);
    myDeck.push_back(2);
    myDeck.push_back(10);
    myDeck.push_front(20);
    myDeck.push_front(30);
    printDeque(myDeck);

    map<string, string> threeKingdoms;
    threeKingdoms["Liu"] = "Bei";
    threeKingdoms["Cao"] = "Cao";

    // https://en.cppreference.com/w/cpp/utility/pair
    // https://www.cplusplus.com/reference/map/map/
    // Map uses pair type
    for (pair<string, string> element : threeKingdoms) {
        cout << element.first << " " << element.second << endl;
    } 

    vector<int> myVector;

    fillVector(myVector);
    printVector(myVector);

    countFives(myVector);

    cout << "Replacing 5s with 99s" << endl;

    // https://www.cplusplus.com/reference/algorithm/replace/
    // Essentially, all fives here becomes 99.
    replace(myVector.begin(), myVector.end(), 5, 99);

    countFives(myVector);
    printVector(myVector);

    cout << endl;
    cout << "sorted" << endl;
    // https://www.cplusplus.com/reference/algorithm/sort/
    sort(myVector.begin(), myVector.end());

    printVector(myVector);


    return 0;
}

void printDeque(deque<int> deck) {
    for (int num: deck) {
        cout << num << endl;
    }    
}

void fillVector(vector<int>& myVector) {
    srand(time(nullptr));
    int temp;
    for (int i = 0; i < 20; i++) {
        temp = rand() % 5 + 1;
        myVector.push_back(temp);
    }
}

void printVector(vector<int>& myVector) {
    for (int element: myVector) {
        cout << element << endl;
    }
}

void countFives(vector<int>& myVector) {
    int numFives = count(myVector.begin(), myVector.end(), 5);
    cout << numFives << endl;
}