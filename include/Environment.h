#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>

// Enum to represent different environments
enum class Environment {
    Prod,
    Staging,
    Dev
};

// Declare functions to be defined in environment.cpp
void setEnvironment(Environment env);
std::string getEnvironmentAsString();
bool isProduction();
bool isStaging();
bool isDev();

#endif // ENVIRONMENT_H
