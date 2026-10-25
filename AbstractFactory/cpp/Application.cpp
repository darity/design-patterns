#include "Application.h"

int main() {

    auto appW = std::make_unique<Application>(std::make_unique<WindowsFactory>());
    appW->createUI();
    appW->render();

    auto appM = std::make_unique<Application>(std::make_unique<MacFactory>());
    appM->createUI();
    appM->render();

}