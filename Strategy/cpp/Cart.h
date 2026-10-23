#ifndef PS_CART_H
#define PS_CART_H
#include <iostream>

class Discount {
public:
    virtual ~Discount(){}
    virtual double useDiscount(double price) = 0;
};

class NoDiscount: public Discount {
public:
    double useDiscount(double price) override {
        return price;
    };
};

class StudentDiscount: public Discount {
public:
    double useDiscount(double price) override {
        return price * 0.8;
    }
};

class HolidayDiscount: public Discount {
public:
    double useDiscount(double price) override{
        return price*0.7;
    }
};

class Cart {
private:
    double price;
    Discount* discount_;
public:
    Cart(double price, Discount* discount): price(price), discount_(discount) {

    }

    void setDiscount(Discount* newDiscount) {
        discount_ = newDiscount;
    }

    double totalPrice() const {
        return discount_->useDiscount(price);
    }
};




#endif //PS_CART_H