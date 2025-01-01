#include "../include/global.h"


void studyOOPs();
void studyMultithreading();
void studyOtherTopics();

void openUserNeededStudyMaterial(OOPS &obj)
{
    int val = obj.userValue;
    if (val != 0)
    {
        switch (val)
        {
        case 1:
            studyOOPs();
            break;
        case 2:
            studyMultithreading();
            break;
        case 3:
            studyOtherTopics();
            break;
        case 4:
            // error.log(LogLevel::ERROR, "Unimplimented methods are demanded for study");
            break;

        default:
            break;
        }
        // checkEncapsulatedData();
        // checkAbstractedData();
        // checkPolymorphismData();
    }
    else
    {
        // error.log(LogLevel::ERROR, "Why user choice is 0????");
    }

}

void studyOOPs()
{

}

void studyMultithreading()
{
    debug.log(DEBUG, "Coming Soon!!!");
}

void studyOtherTopics()
{
    auto data = std::string();
    std::cout << "Enter the topic name you want to study"<< std::endl;
    std::cin >> data;

    info.log(INFO, "User requirement -> " + data);
    Sleep(20);

    debug.print("Thankyou for your interest in learning " + data + ". Will update to dev.",GREEN);
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
    AbstractedPerson person("John Doe", 12345);
    person.getdetails();
}
