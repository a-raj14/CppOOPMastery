#include "include/global.h"
//Hello World This is the start of your program.
int main() 
{
    if (isProduction())
        displayWelcomeMessage();

    callStudyMethods();

    if (isProduction()) {
        askUserToRestartStudy();
        askUserToNotes();
        printThankYou();
    }
    exit(0);
    debug.print("Application execution ended.", GREEN);
    return 0;
}
