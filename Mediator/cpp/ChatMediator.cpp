#include "ChatMediator.h"
#include <memory>

int main() {
    auto chatRoom = std::make_unique<ChatRoom>();
    auto ana = std::make_unique<User>("Ana", chatRoom.get());
    auto marko = std::make_unique<User>("Marko", chatRoom.get());
    auto jovan = std::make_unique<User>("Jovan", chatRoom.get());

    chatRoom->addUser(ana.get());
    chatRoom->addUser(marko.get());
    chatRoom->addUser(jovan.get());

    ana->send("Hello everyone");
    marko->send("Hi Ana");
}
