#include "Transport.h"

int main() {
    std::unique_ptr<Logistics> roadLogistics = std::make_unique<RoadLogistics>();
    roadLogistics->planDelivery();

    std::unique_ptr<Logistics> seaLogistics = std::make_unique<SeaLogistics>();
    seaLogistics->planDelivery();
}