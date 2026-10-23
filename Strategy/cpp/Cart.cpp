#include "Cart.h"

int main() {
    NoDiscount noDiscount;
    StudentDiscount studentDiscount;
    HolidayDiscount holidayDiscount;

    Cart cart(1000, &noDiscount);
    std::cout << "No discount price: "<< cart.totalPrice()<<std::endl;

    cart.setDiscount(&studentDiscount);
    std::cout << "Student discount price: "<< cart.totalPrice()<<std::endl;

    cart.setDiscount(&holidayDiscount);
    std::cout << "Holiday discount price: "<< cart.totalPrice()<<std::endl;
}