#include <iostream>
#include <string>
#include <deque>
#include <map>
//https://www.cplusplus.com/reference/algorithm/
// #include <algorithm>

using namespace std;

void printDeque(deque<int> deck);

int main() {
    deque<int> myDeck;

    myDeck.push_back(1);
    myDeck.push_back(2);
    myDeck.push_back(10);
    printDeque(myDeck);

    myDeck.push_front(20);
    myDeck.push_front(30);
    printDeque(myDeck);

    map<string, string> threeKingdoms;
    threeKingdoms["Liu"] = "Bei";
    threeKingdoms["Cao"] = "Cao";

    for (pair<string, string> element : threeKingdoms) {
        cout << element.first << " " << element.second << endl;
    } 

    return 0;
}

void printDeque(deque<int> deck) {
    for (int num: deck) {
        cout << num << endl;
    }    
}