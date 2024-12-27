#include <iostream>
#include <cstring>
#include "../include/oppsFileInclude/Abstraction.h"

AbstractedPerson::AbstractedPerson(const char* name, int id) {
    // Assign values to name and id
    strncpy(this->name, name, sizeof(this->name) - 1);  // Ensure no buffer overflow
    this->name[sizeof(this->name) - 1] = '\0';          // Null terminate the string
    this->id = id;
}

void AbstractedPerson::getdetails() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
}
