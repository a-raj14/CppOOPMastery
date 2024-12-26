#include <iostream>
#include "Abstraction.cpp"
#include "Encapsulate.cpp"

void checkEncapsulatedData();
void checkAbstractedData();

int main()
{
    std::cout << "Starting Program..... " << endl;
    main_local(); // test other files inclued in these run or not.
    std::cout << "Calling Encapsulated Data" << endl;
    checkEncapsulatedData();
    std::cout << "Calling Abstracted Data" << endl;
    checkAbstractedData();
    return 0;
}

void checkEncapsulatedData()
{
    EncapsulatedPerson person("John Doe", 30);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    person.setName("Krish");
    person.setAge(32);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;
}

void checkAbstractedData()
{
    Abstractedperson p;
    p.getdetails();
}
