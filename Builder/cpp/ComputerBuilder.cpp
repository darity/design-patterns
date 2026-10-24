#include "ComputerBuilder.h"

int main() {
    auto office = std::make_unique<OfficeComputerBuilder>();
    auto director = std::make_unique<Director>(office.get());

    director->construct();
    office->getResult()->show();

    GamingComputerBuilder gamingBuilder;
    Director gamingDirector(&gamingBuilder);
    gamingDirector.construct();
    gamingBuilder.getResult()->show();

}