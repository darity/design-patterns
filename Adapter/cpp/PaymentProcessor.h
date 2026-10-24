#ifndef PS_PAYMENTPROCESSOR_H
#define PS_PAYMENTPROCESSOR_H
#include <iostream>
#include <cmath>

// Target
class PaymentProcessor {
public:
    virtual ~PaymentProcessor() = default;

    virtual void pay(double amountInEuros) = 0;
};

// Adaptee
class OldBankApi {
public:
    void makePayment(int amountInCents) {
        std::cout<<"Old bank API: paid "<<amountInCents<<" cents"<<std::endl;
    }
};

// Adapter
class BankAdapter: public PaymentProcessor {
public:
    explicit BankAdapter(OldBankApi* oldBank): oldBankApi(oldBank) {}

    void pay(double amountInEuros) override {
        oldBankApi->makePayment(std::lround(amountInEuros*100));
    }

private:
    OldBankApi* oldBankApi;
};

// Client
class Checkout {
public:
    explicit Checkout(PaymentProcessor* paymentP): paymentProcessor(paymentP){}

    void buy(double price) {
        std::cout<<"Processing purchase..."<<std::endl;
        paymentProcessor->pay(price);
    }
private:
    PaymentProcessor* paymentProcessor;
};

#endif //PS_PAYMENTPROCESSOR_H