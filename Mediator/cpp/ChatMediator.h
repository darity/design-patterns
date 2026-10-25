#ifndef PS_CHATMEDIATOR_H
#define PS_CHATMEDIATOR_H
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class User;

class ChatMediator {
public:
    virtual ~ChatMediator() = default;
    virtual void addUser(User* user) = 0;
    virtual void sendMessage(std::string message, User* sender) = 0;
};

class User {
public:
    User(std::string name, ChatMediator* mediator):
    name_(std::move(name)), mediator_(mediator){}

    void send(const std::string& message) {
        std::cout<<name_<<" sends: "<<message<<std::endl;
        mediator_->sendMessage(message, this);
    }

    void receive(const std::string & message) const {
        std::cout<<name_<<" received: "<<message<<std::endl;
    }

private:
    std::string name_;
    ChatMediator* mediator_;
};


class ChatRoom final: public ChatMediator {
public:
    void addUser(User *user) override {
        users.push_back(user);
    }

    void sendMessage(const std::string message, User *sender) override {
        for (User* usr: users) {
            if (usr == sender) continue;
            usr->receive(message);
        }
    }
private:
    std::vector<User*> users;
};
#endif //PS_CHATMEDIATOR_H