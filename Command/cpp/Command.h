#ifndef PS_COMMAND_H
#define PS_COMMAND_H
#include <iostream>

class Command {
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver
class Light {
public:
    void on() {
        std::cout<<"Light is ON"<<std::endl;
    }

    void off() {
        std::cout<<"Light is OFF"<<std::endl;
    }
};

class LightOnCommand final: public Command {
public:

    explicit LightOnCommand(Light* setLight): light(setLight){}

    void execute() override {
        light->on();
    }

    void undo() override {
        light->off();
    }
private:
    Light* light;
};

class LightOffCommand final: public Command {
public:

    explicit LightOffCommand(Light* setLight) {
        light = setLight;
    }

    void execute() override {
        light->off();
    }

    void undo() override {
        light->on();
    }
private:
    Light* light;
};

// Invoker
class RemoteControl {
public:
    void setCommand(Command* newCommand) {
        command = newCommand;
    }

    void pressButton() {
        if (command) {
            command->execute();
            lastCommand = command;
        }
    }

    void pressUndo() const {
        if (lastCommand) lastCommand->undo();
    }
private:
    Command* command = nullptr;
    Command* lastCommand = nullptr;
};

#endif //PS_COMMAND_H