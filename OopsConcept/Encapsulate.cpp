#include "../include/oppsFileInclude/Encapsulation.h"  // Include the header file for EncapsulatedPerson class

// Constructor definition
EncapsulatedPerson::EncapsulatedPerson(string name, int age)
{
    this->name = name;
    this->age = age;
}

// Setter for name
void EncapsulatedPerson::setName(string name)
{
    this->name = name;
}

// Getter for name
string EncapsulatedPerson::getName()
{
    return name;
}

// Setter for age
void EncapsulatedPerson::setAge(int age)
{
    this->age = age;
}

// Getter for age
int EncapsulatedPerson::getAge()
{
    return age;
}
