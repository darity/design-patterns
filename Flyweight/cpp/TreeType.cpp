#include "TreeType.h"

int main() {

    auto forest = std::make_unique<Forest>();
    forest->plantTree(1,2,"Oak", "Green");
    forest->plantTree(3, 4, "Pine", "DarkGreen");
    forest->plantTree(5, 6, "Oak", "Green");
    forest->plantTree(7, 8, "Oak", "Green");

    forest->draw();
    std::cout<<"Forest size: "<<forest->forestSize()<<std::endl;
}