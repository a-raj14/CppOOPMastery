#include<iostream>
#include<string>

class Polymorphism{
public:
    void func(int x)
    {
        std::cout << x << std::endl;
    }

    void func(int x,int y)
    {
        std::cout << x << " " << y << std::endl;
    }

    void func(std::string firstName, std::string secondName)
    {
        std::cout << "user name is " << firstName << " " << secondName << std::endl;
    }
};