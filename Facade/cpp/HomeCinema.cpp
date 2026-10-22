#include "HomeCinema.h"

void HomeCinema::startMovie() const {
    light_.dim();
    projector_.turnOn();
    sound_.turnOn();
    sound_.changeSoundLevel(7);
}

void HomeCinema::endMovie() const {
    sound_.turnOff();
    projector_.turnOff();
    light_.turnOn();
}

int main() {
    HomeCinema cinema;
    cinema.startMovie();
    std::cout<<"--- film is rolling ---"<< std::endl;
    cinema.endMovie();
}