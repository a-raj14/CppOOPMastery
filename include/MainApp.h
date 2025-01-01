#ifndef MAINAPP_H
#define MAINAPP_H

#include <string>

class MainApp {
public:
    static MainApp& getInstance();  
    void typeEffect(const std::string& colorCode, const std::string& message, int delay = 1);
private:
    MainApp() = default;                           
    ~MainApp() = default;                          
    MainApp(const MainApp&) = delete;              
    MainApp& operator=(const MainApp&) = delete;   
};

void displayWelcomeMessage();
int askUserWhatToLearn();
void askUserToNotes();
void askUserToRestartStudy();
void callStudyMethods();
void waitForDelay(int delay_seconds);
void manualDealy(int delay_seconds);
void printThankYou();
std::string rocketEmoji();

#endif // MAINAPP_H
