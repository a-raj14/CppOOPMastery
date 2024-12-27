#ifndef ENCAPSULATEDPERSON_H
#define ENCAPSULATEDPERSON_H

#include <string>

using namespace std;

class EncapsulatedPerson
{
private:
    string name;
    int age;

public:
    // Constructor
    EncapsulatedPerson(string name, int age);

    // Setter and Getter for name
    void setName(string name);
    string getName();

    // Setter and Getter for age
    void setAge(int age);
    int getAge();
};

#endif // ENCAPSULATEDPERSON_H
