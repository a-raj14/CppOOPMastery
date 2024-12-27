#include <iostream>
#include <string>

using namespace std;

class EncapsulatedPerson
{
private:
    string name;
    int age;

public:
    EncapsulatedPerson(string name, int age) // constructor
    {
        this->name = name;
        this->age = age;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
};
