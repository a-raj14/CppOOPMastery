#include <iostream>
#include "include/oops.h"
#include "include/logger.h"
#include "include/function.h"
#include <chrono>
#include <thread>
#ifdef _WIN32
#include <windows.h>  // For Sleep on Windows
#else
#include <unistd.h>  // For sleep on non-Windows platforms (e.g., Linux, macOS)
#endif

void waitForDelay(int delay_seconds) {
    #ifdef _WIN32
    Sleep(delay_seconds * 1000);  // Sleep takes milliseconds in Windows
#else
    std::this_thread::sleep_for(std::chrono::seconds(delay_seconds));  // Cross-platform sleep
#endif
    
}

void manualDealy(int delay_seconds)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    
    while (true) {
        // Get the current time
        auto current_time = std::chrono::high_resolution_clock::now();
        
        // Calculate elapsed time
        std::chrono::duration<int> elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time);
        
        // If the delay time has passed, break the loop
        if (elapsed_seconds.count() >= delay_seconds) {
            break;
        }
    }
}

void displayWelcomeMessage() {
    std::cout << "\n\n";
    std::cout << "===============================" << std::endl;
    std::cout << "   Welcome to C++ OOP Mastery   " << std::endl;
    std::cout << "===============================" << std::endl;
    
    waitForDelay(1);  // Wait for 1 second before continuing

    std::cout << "\nPlease hold on...\n";
    std::cout << "Getting things ready for your OOP adventure...\n";

    waitForDelay(2);  // Wait for 2 seconds

    std::cout << "\n===============================" << std::endl;
    std::cout << "   All systems are go! 🚀   " << std::endl;
    std::cout << "===============================" << std::endl;

    waitForDelay(1);  // Wait for 1 second before the final message

    std::cout << "Program execution started.\n";
    std::cout << "Let's dive into the world of C++ OOP!\n";
}

void askUserWhatToLearn() {
    std::cout << "\nWhat would you like to learn today?\n";
    std::cout << "1. OOP Concepts (Encapsulation, Abstraction, Polymorphism)\n";
    std::cout << "2. Multithreading\n";
    std::cout << "3. Other Topics\n";
    std::cout << "Please enter your choice (1/2/3): ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "\nYou chose OOP Concepts!\n";
    } else if (choice == 2) {
        std::cout << "\nMultithreading - Coming Soon!\n";
    } else if (choice == 3) {
        std::cout << "\nExplore other cool topics on the way!\n";
    } else {
        std::cout << "\nInvalid choice, please choose a valid option.\n";
        askUserWhatToLearn();
    }
}

int main()
{
    displayWelcomeMessage();

    // Ask what the user wants to learn
    askUserWhatToLearn();
    debug.log(DEBUG, "Application exeution ended.");
    return 0;
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
    AbstractedPerson person("John Doe", 12345);
    person.getdetails();
}
