#include "Logger.h"
#include <iostream>

Logger* Logger::instance = nullptr;

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

void Logger::log(std::string message) {
    numOfMessages++;
    std::cout<< "[" << numOfMessages << "] " << message << std::endl;
}

int main() {
    Logger* a = Logger::getInstance();
    Logger* b = Logger::getInstance();

    a->log("Program started");
    b->log("Loading data");

    std::cout<< (a==b) << std::endl;
}