#ifndef PS_REMOTECONTROL_H
#define PS_REMOTECONTROL_H
#include <iostream>

class Device {
public:
    virtual ~Device() = default;
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual void setVolume(int volume) = 0;
    virtual int getVolume() = 0;
    virtual bool isEnabled() = 0;
};

class Tv: public Device {
public:

    void enable() override {
        enabled = true;
        std::cout<<"Tv: enabled"<<std::endl;
    }

    void disable() override {
        enabled = false;
        std::cout<<"Tv: disabled"<<std::endl;
    }

    void setVolume(int volume) override {
        volume_ = volume;
        std::cout<<"Tv: volume set to "<<volume_<<std::endl;
    }

    int getVolume() override {
        return volume_;
    }

    bool isEnabled() override {
        return enabled;
    }

private:
    bool enabled = false;
    int volume_ = 10;
};

class Radio: public Device {
public:

    void enable() override {
        enabled = true;
        std::cout<<"Radio: enabled"<<std::endl;
    }

    void disable() override {
        enabled = false;
        std::cout<<"Radio: disabled"<<std::endl;
    }

    void setVolume(int volume) override {
        volume_ = volume;
        std::cout<<"Radio: volume set to "<<volume_<<std::endl;
    }

    int getVolume() override {
        return volume_;
    }

    bool isEnabled() override {
        return enabled;
    }

private:
    bool enabled = false;
    int volume_ = 10;
};

class RemoteControl {
public:
    virtual ~RemoteControl() = default;

    explicit RemoteControl(Device* device): device_(device){}

    void togglePower() const {
        device_->isEnabled()? device_->disable(): device_->enable();
    }

    void volumeUp() const {
        device_->setVolume(device_->getVolume()+10);
    }

    void volumeDown() const {
        device_->setVolume(device_->getVolume()-10);
    }

protected:
    Device* device_;
};

class AdvancedRemoteControl: public RemoteControl {
public:
    explicit AdvancedRemoteControl(Device* device): RemoteControl(device) {}

    void mute() const {
        device_->setVolume(0);
    }
};

#endif //PS_REMOTECONTROL_H