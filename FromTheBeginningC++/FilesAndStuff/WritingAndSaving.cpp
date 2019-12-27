#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::ofstream newFile("Hello.txt");
    newFile << "Some file." << endl;
    return 0;
}