#ifndef PS_WEATHERSTATION_H
#define PS_WEATHERSTATION_H
#include <algorithm>
#include <iostream>
#include <vector>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(double temperature) = 0;
};

// Subject
class WeatherStation {
public:
    void attach(Observer* observer) {
        observerList.push_back(observer);
    }

    void detach(Observer* observer) {
        observerList.erase(
         std::remove(observerList.begin(), observerList.end(), observer),
         observerList.end());
    }

    void setTemperature(double temp) {
        currentTemperature = temp;
        for (Observer* obs: observerList) {
            obs->update(currentTemperature);
        }
    }
private:
    std::vector<Observer*> observerList;
    double currentTemperature = 0;
};

// Concrete observer
class PhoneDisplay: public Observer {
public:

    void update(double temperature) override {
        std::cout<<"Phone display: "<<temperature<<" C"<<std::endl;
    }
};

// Concrete observer
class WindowDisplay: public Observer {
public:
    void update(double temperature) override {
        std::cout<<"Window display: "<<temperature<<" C"<<std::endl;
    }
};


#endif //PS_WEATHERSTATION_H