#include <iostream>
#include "OopsConcept/Abstraction.cpp"
#include "OopsConcept/Encapsulate.cpp"
#include "OopsConcept/Polymorphism.cpp"



void checkEncapsulatedData();
void checkAbstractedData();
void checkPolymorphismData();

int main()
{
    std::cout << "Starting C++ Program..... " << std::endl;
    main_local(); // test other files inclued in these run or not.
    std::cout << "Calling Encapsulated Data" << std::endl;
    checkEncapsulatedData();
    std::cout << "Calling Abstracted Data" << std::endl;
    checkAbstractedData();
    std::cout << "Calling Polymorphism Data" << std::endl;
    checkPolymorphismData();
    return 0;
}

void checkPolymorphismData()
{
    std::cout << "Which polymorphism function you want to know \n Type 1 for Compile time polymorphism or Type 2 for runtime polymorphism" << std::endl;
    int data;
    std::cin >> data;
    if(data == 1)
    {
        Polymorphism polymorphism;
        polymorphism.func(1);
        polymorphism.func(1, 2);
        polymorphism.func("ayush", "rajput");
    }
    else if(data ==2)
    {
        std::cout << "Still under development" << std::endl;
    }
    else
    {
        std::cout << "Please enter correct value" << endl;
    }
}

void checkEncapsulatedData()
{
    EncapsulatedPerson person("John Doe", 30);

    cout << "Name: " << person.getName() << std::endl;
    cout << "Age: " << person.getAge() << std::endl;

    person.setName("Krish");
    person.setAge(32);

    cout << "Name: " << person.getName() << std::endl;
    cout << "Age: " << person.getAge() << std::endl;
}

void checkAbstractedData()
{
    Abstractedperson p;
    p.getdetails();
}
