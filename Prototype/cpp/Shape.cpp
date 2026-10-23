#include "Shape.h"

int main() {
    auto circle = std::make_unique<Circle>("red", 5);
    auto rectangle = std::make_unique<Rectangle>("blue", 4,6);

    std::unique_ptr<Shape> circleClone = circle->clone();
    std::unique_ptr<Shape> rectangleClone = rectangle->clone();

    circleClone->setColor("green");
    rectangleClone->setColor("purple");

    circle->draw();
    circleClone->draw();

    rectangle->draw();
    rectangleClone->draw();
}