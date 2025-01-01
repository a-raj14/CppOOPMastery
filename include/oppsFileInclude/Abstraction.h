#ifndef ABSTRACTION_H
#define ABSTRACTION_H
#include <iostream>

class AbstractedPerson {
private:
    char name[20];  // Name of the person
    int id;         // ID of the person

public:
    // Constructor to initialize details (optional, but helpful)
    AbstractedPerson(const char* name, int id);

    // Function to display person details
    void getdetails() const;
};

#endif // ABSTRACTION_H
