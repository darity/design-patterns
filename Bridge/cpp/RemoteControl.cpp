#include "RemoteControl.h"

#include <memory>

int main() {
    auto tv = std::make_unique<Tv>();
    auto radio = std::make_unique<Radio>();

    auto remote = std::make_unique<RemoteControl>(tv.get());

    auto advancedRemote = std::make_unique<AdvancedRemoteControl>(radio.get());

    remote->togglePower();
    remote->volumeUp();

    advancedRemote->togglePower();
    advancedRemote->mute();
}
