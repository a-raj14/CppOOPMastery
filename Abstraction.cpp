#include <iostream>
using namespace std;

// tuple<int,string>

void main_local()
{
    cout << "Testing other files....." << endl;
}

class Abstractedperson
{
    char name[20];
    int id;

public:
    void getdetails()
    {
        std::cout << name << endl;
        std::cout << id << endl;
    }
};
