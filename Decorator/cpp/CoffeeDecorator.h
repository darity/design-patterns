#ifndef PS_COFFEEDECORATOR_H
#define PS_COFFEEDECORATOR_H
#include <string>

// Component
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string getDescription() = 0;
    virtual double getCost() = 0;
};

// Concrete component
class SimpleCoffee: public Coffee {
public:
    std::string getDescription() override {
        return "Simple coffee";
    }

    double getCost() override {
        return 2.0;
    }
};

// Abstract decorator
class CoffeeDecorator: public Coffee {
public:
    explicit CoffeeDecorator(Coffee* coffee) :coffee_(coffee){
    }

    std::string getDescription() override {
        return coffee_->getDescription();
    }

    double getCost() override {
        return coffee_->getCost();
    }

protected:
    Coffee* coffee_;
};

// Concrete decorator
class MilkDecorator: public CoffeeDecorator {
public:
    explicit MilkDecorator(Coffee* coffee): CoffeeDecorator(coffee){}

    std::string getDescription() override {
        return coffee_->getDescription() + ", milk";
    }

    double getCost() override {
        return coffee_->getCost() + 0.5;
    }
};

// Concrete decorator
class WhipDecorator: public CoffeeDecorator {
public:
    explicit WhipDecorator(Coffee* coffee): CoffeeDecorator(coffee){}

    std::string getDescription() override {
        return coffee_->getDescription()+", whip";
    }

    double getCost() override {
        return coffee_->getCost() + 0.7;
    }
};
#endif //PS_COFFEEDECORATOR_H