#include "Beverage.h"

#include <iostream>

void Beverage::prepare() {
    boilWater();
    brew();
    pourIntoCup();
    addCondiment();
}

void Beverage::boilWater() {
    std::cout<<"Boiling water..."<<std::endl;
}

void Beverage::pourIntoCup() {
    std::cout<<"Pouring into cup..."<<std::endl;
}

void Tea::brew() {
    std::cout<<"Steeping the tea bag..."<<std::endl;
}

void Tea::addCondiment() {
    std::cout<<"Adding lemon..."<<std::endl;
}

void Coffee::brew() {
    std::cout<<"Dripping the coffee"<<std::endl;
}

void Coffee::addCondiment() {
    std::cout<<"Adding milk..."<<std::endl;
}


int main() {
    Beverage* tea = new Tea();
    std::cout<<"------Tea------"<<std::endl;
    tea->prepare();

    Beverage* coffee = new Coffee;
    std::cout<<"-----Coffee-----"<<std::endl;
    coffee->prepare();

    delete tea;
    delete coffee;
}