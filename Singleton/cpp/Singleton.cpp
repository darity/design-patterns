#include "Singleton.h"
#include <iostream>

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

void Singleton::log(std::string message) {
    numOfMessages++;
    std::cout<< "[" << numOfMessages << "] " << message << std::endl;
}

int main() {
    Singleton* a = Singleton::getInstance();
    Singleton* b = Singleton::getInstance();

    a->log("Program started");
    b->log("Loading data");

    std::cout<< (a==b) << std::endl;
}