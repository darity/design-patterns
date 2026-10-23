#ifndef PS_SHAPE_H
#define PS_SHAPE_H
#include <iostream>
#include <memory>
#include <string>
#include <utility>


class Shape {
public:
    virtual ~Shape() = default;
    explicit Shape(std::string color): color(std::move(color)){}

    virtual std::unique_ptr<Shape> clone() = 0;
    virtual void draw() = 0;

    void setColor(std::string newColor) {
        color = std::move(newColor);
    }
protected:
    std::string color;
};

class Circle final : public Shape {
public:
    explicit Circle(std::string color, int radius) : Shape(std::move(color)), radius(radius) {}

    void draw() override {
        std::cout<<"Drawing a "<< color <<" circle with radius "<< radius << std::endl;
    };

    std::unique_ptr<Shape> clone() override {
        return std::make_unique<Circle>(color, radius);
    }

private:
    int radius;
};

class Rectangle final : public Shape {
public:
    explicit Rectangle(std::string color, int width, int height):
    Shape(std::move(color)), width(width), height(height){}

    void draw() override {
        std::cout<<"Drawing a "<< color <<" rectangle "<<width<<"x"<<height<<std::endl;
    }

    std::unique_ptr<Shape> clone() override {
        return std::make_unique<Rectangle>(color, width, height);
    }
private:
    int width;
    int height;
};

#endif //PS_SHAPE_H