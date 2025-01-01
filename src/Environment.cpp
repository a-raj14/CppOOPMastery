#include "../include/Environment.h"

// Static variable to hold the current environment
static Environment currentEnv = Environment::Prod;  //Change Default environment to Dev while development

// Define the functions

void setEnvironment(Environment env) {
    currentEnv = env;
}

std::string getEnvironmentAsString() {
    switch (currentEnv) {
        case Environment::Prod: return "Production";
        case Environment::Staging: return "Staging";
        case Environment::Dev: return "Development";
        default: return "Unknown";
    }
}

bool isProduction() {
    return currentEnv == Environment::Prod;
}

bool isStaging() {
    return currentEnv == Environment::Staging;
}

bool isDev() {
    return currentEnv == Environment::Dev;
}
