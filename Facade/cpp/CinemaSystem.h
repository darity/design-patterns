#ifndef PS_CINEMASYSTEM_H
#define PS_CINEMASYSTEM_H
#include <iostream>

class Projector {
public:
    static void turnOn() {
        std::cout<<"Projector turned on" << std::endl;
    }
    static void turnOff() {
        std::cout<<"Projector turned off" << std::endl;
    };
};

class Sound {
public:
    static void turnOn() {
        std::cout<<"Sound turned on" << std::endl;
    }
    static void turnOff() {
        std::cout<<"Sound turned off" << std::endl;
    }
    static void changeSoundLevel(int level) {
        std::cout<<"Sound level: " << level << std::endl;
    }
};

class Light {
public:
    static void dim() {
        std::cout<<"Light is dimmed"<< std::endl;
    }
    static void turnOn() {
        std::cout<<"Light turned on"<< std::endl;
    }
};
#endif //PS_CINEMASYSTEM_H