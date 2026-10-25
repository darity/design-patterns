#ifndef PS_APPLICATION_H
#define PS_APPLICATION_H
#include <iostream>
#include <memory>

// Product
class Button {
public:
    virtual ~Button() = default;
    virtual void render() = 0;
};

// Product
class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void render() = 0;
};

// Concrete product
class WindowsButton: public Button {
public:
    void render() override {
        std::cout<<"Rendering Windows button"<<std::endl;
    }
};

// Concrete product
class WindowsCheckbox: public Checkbox {
public:
    void render() override {
        std::cout<<"Rendering Windows checkbox"<<std::endl;
    }
};

// Concrete product
class MacButton: public Button {
public:
    void render() override {
        std::cout<<"Rendering Mac button"<<std::endl;
    }
};

// Concrete product
class MacCheckbox: public Checkbox {
public:
    void render() override {
        std::cout<<"Rendering Mac checkbox"<<std::endl;
    }
};

// Abstract Factory
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() = 0;
};

// Concrete factory
class WindowsFactory: public GUIFactory{
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<WindowsButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<WindowsCheckbox>();
    }
};

// Concrete factory
class MacFactory: public GUIFactory{
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<MacButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<MacCheckbox>();
    }
};

class Application {
public:
    explicit Application(std::unique_ptr<GUIFactory> factory):
    factory_(std::move(factory)) {}

    void createUI() {
        button_ = factory_->createButton();
        checkbox_ = factory_->createCheckbox();
    }

    void render() const {
        button_->render();
        checkbox_->render();
    }

private:
    std::unique_ptr<GUIFactory> factory_;
    std::unique_ptr<Button> button_;
    std::unique_ptr<Checkbox> checkbox_;
};


#endif //PS_APPLICATION_H