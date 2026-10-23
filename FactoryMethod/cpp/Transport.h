#ifndef PS_TRANSPORT_H
#define PS_TRANSPORT_H

#include <iostream>
#include <memory>

// Product
class Transport {
public:
    virtual ~Transport() = default;
    virtual void deliver() = 0;
};

// Concrete product
class Truck final: public Transport {
public:
    void deliver() override {
        std::cout<<"Delivering by land in a truck"<<std::endl;
    }
};

// Concrete product
class Ship final: public Transport {
public:
    void deliver() override {
        std::cout<<"Delivering by sea in a ship"<<std::endl;
    }
};

// Creator
class Logistics {
public:
    virtual ~Logistics() = default;

    void planDelivery() {
        std::cout<<"Planning delivery..."<<std::endl;
        std::unique_ptr<Transport> transport = createTransport();
        transport->deliver();
    }
protected:
    //Factory Method
    virtual std::unique_ptr<Transport> createTransport() = 0;
};

// Concrete creator
class RoadLogistics final: public Logistics {
protected:
    std::unique_ptr<Transport> createTransport() override {
        return std::make_unique<Truck>();
    }
};

// Concrete creator
class SeaLogistics final: public Logistics {
protected:
    std::unique_ptr<Transport> createTransport() override {
        return std::make_unique<Ship>();
    }
};

#endif //PS_TRANSPORT_H