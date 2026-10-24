#include "Command.h"

#include <memory>

int main() {
    auto light = std::make_unique<Light>();
    auto lightOnCommand = std::make_unique<LightOnCommand>(light.get());
    auto lightOffCommand = std::make_unique<LightOffCommand>(light.get());

    auto remoteControl = std::make_unique<RemoteControl>();

    remoteControl->pressButton();
    remoteControl->setCommand(lightOnCommand.get());
    remoteControl->pressButton();
    remoteControl->setCommand(lightOffCommand.get());
    remoteControl->pressButton();
    remoteControl->pressUndo();
}
