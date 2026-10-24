#include "CoffeeDecorator.h"

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<Coffee> simple = std::make_unique<SimpleCoffee>();
    std::unique_ptr<Coffee> milk= std::make_unique<MilkDecorator>(simple.get());
    std::unique_ptr<Coffee> whip = std::make_unique<WhipDecorator>(milk.get());

    std::cout<<whip->getDescription()<<" costs "<<whip->getCost()<<std::endl;
}
