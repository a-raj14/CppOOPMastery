#include "include/global.h"
#include "include/MainApp.h"
#include <iostream>
#include <chrono>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

MainApp& MainApp::getInstance() {
    static MainApp instance;
    return instance;
}

void MainApp::typeEffect(const std::string& colorCode, const std::string& message, int delay) {
    std::cout << colorCode;
    for (char c : message) {
        std::cout << c << std::flush;
        #ifdef _WIN32
        Sleep(delay);
        #else
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        #endif
    }
    std::cout << RESET;
}

void waitForDelay(int delay_seconds) {
    #ifdef _WIN32
    Sleep(delay_seconds * 1000);
    #else
    std::this_thread::sleep_for(std::chrono::seconds(delay_seconds));
    #endif
}

std::string rockEmoji() {
    return "<3";
}

std::string smileEmoji() {
    return "^_^";
}

void displayWelcomeMessage() {
    MainApp& app = MainApp::getInstance();  // Use Singleton instance
    std::cout << "\n\n";
    std::cout << GREEN << "===============================\n";
    std::cout << CYAN << "   Welcome to C++ OOP Mastery   \n";
    std::cout << GREEN << "===============================\n" << RESET;

    waitForDelay(1);
    app.typeEffect(YELLOW, "\nPlease hold on...\n", 50);
    app.typeEffect(YELLOW, "\nGetting things ready for your OOP adventure... \n", 50);
    waitForDelay(1);

    std::cout << GREEN << "\n===============================\n";
    std::cout << MAGENTA << "   All systems are go! " << rockEmoji() << "   \n";
    std::cout << GREEN << "===============================\n" << RESET;

    waitForDelay(1);
    app.typeEffect(CYAN, "Program execution started.\n", 30);
    std::cout << "Let's dive into the world of C++ OOP!\n";
}


void printThankYou() {
    MainApp& app = MainApp::getInstance();  // Use Singleton instance

    std::cout << "called" << std::endl;
    std::cout << GREEN;
    std::cout << "\n***************************\n";
    std::cout << " *  " << YELLOW << "T H A N K  Y O U !" << GREEN << "  *\n";
    std::cout << "***************************\n" << RESET;

    app.typeEffect(CYAN, "\nWishing you ", 20);
    app.typeEffect(MAGENTA, "success ", 20);
    app.typeEffect(CYAN, "and ", 20);
    app.typeEffect(YELLOW, "growth ", 20);
    app.typeEffect(CYAN, "ahead!\n", 20);

    app.typeEffect(MAGENTA, "\nStay curious, stay learning!  " + smileEmoji() + "\n", 30);
}


void askUserToNotes()
{
    std::cout << "\n Do you want to get Notes for this ? [y/n]" << std::endl;
    std::string c;
    cin >> c;
    if(c == "y" || c == "yes")
    {
        std::cout << "Url : " << NotesUrl << std::endl;
        WebHelper::openURL(NotesUrl);

    }
    else if(c == "n" || c == "no")
    {
        return;
    }
    else
    {
        askUserToNotes();
    }
}

void askUserToRestartStudy()
{
    std::cout << "\n Do you want to study more concepts ? [y/n]" << std::endl;
    std::string c;
    cin >> c;
    if(c == "y" || c == "yes")
    {
        callStudyMethods();
    }
    else if(c == "n" || c == "no")
    {
        return;
    }
    else
    {
        askUserToRestartStudy();
    }
}

void callStudyMethods()
{
    OOPS oops(askUserWhatToLearn());
    openUserNeededStudyMaterial(oops);
}

int askUserWhatToLearn() {
    std::cout << "\nWhat would you like to learn today?\n";
    std::cout << "1. OOP Concepts (Encapsulation, Abstraction, Polymorphism)\n";
    std::cout << "2. Multithreading\n";
    std::cout << "3. Other Topics\n";
    std::cout << "Please enter your choice (1/2/3): or for exit press e : ";

    auto choice = std::string();
    std::cin >> choice;

    if (choice == "1") {
        std::cout << "\nYou chose OOP Concepts!\n";
    } else if (choice == "2") {
        std::cout << "\nMultithreading - Coming Soon!\n";
    } else if (choice == "3") {
        std::cout << "\nExplore other cool topics on the way!\n";
    } else if (choice == "e") {
        return 0;
    }
    else
    {
        std::cout << "\nInvalid choice, please choose a valid option.\n";
        askUserWhatToLearn();
    }
    return std::stoi(choice);
}