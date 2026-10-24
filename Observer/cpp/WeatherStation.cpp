#include "WeatherStation.h"

#include <memory>

int main() {
    auto station = std::make_unique<WeatherStation>();
    auto phone = std::make_unique<PhoneDisplay>();
    auto window = std::make_unique<WindowDisplay>();

    station->attach(phone.get());
    station->attach(window.get());
    station->setTemperature(21.5);

    station->detach(phone.get());
    station->setTemperature(18.0);
}
