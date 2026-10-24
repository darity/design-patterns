#ifndef PS_COMPUTERBUILDER_H
#define PS_COMPUTERBUILDER_H
#include <iostream>
#include <memory>
#include <string>

// Product
class Computer {
public:

    void setCpu(std::string cpu) { cpu_ = std::move(cpu); }
    void setRam(std::string ram) { ram_ = std::move(ram); }
    void setStorage(std::string storage) { storage_ = std::move(storage); }
    void setGpu(bool hasGpu) { hasGpu_ = hasGpu; }

    void show() const {
        std::cout << "Computer: CPU=" << cpu_
          << ", RAM=" << ram_
          << ", Storage=" << storage_
          << ", GPU=" << (hasGpu_ ? "yes" : "no") << std::endl;
    }
private:
    std::string cpu_, ram_, storage_;
    bool hasGpu_ = false;
};

class ComputerBuilder {
public:
    virtual ~ComputerBuilder() = default;
    virtual void buildCpu() = 0;
    virtual void buildRam() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGpu() = 0;
    virtual std::unique_ptr<Computer> getResult() = 0;
};

class OfficeComputerBuilder: public ComputerBuilder {
public:
    OfficeComputerBuilder(): computer_(std::make_unique<Computer>()){}

    void buildCpu() override {
        computer_->setCpu("Intel i3");
    }

    void buildGpu() override {
        computer_->setGpu(false);
    }

    void buildRam() override {
        computer_->setRam("8GB");
    }

    void buildStorage() override {
        computer_->setStorage("256GB SSD");
    }

    std::unique_ptr<Computer> getResult() override {
        return std::move(computer_);
    }

private:
    std::unique_ptr<Computer> computer_;
};

class GamingComputerBuilder: public ComputerBuilder {
public:
    GamingComputerBuilder(): computer_(std::make_unique<Computer>()){}

    void buildCpu() override {
        computer_->setCpu("Intel i9");
    }

    void buildGpu() override {
        computer_->setGpu(true);
    }

    void buildRam() override {
        computer_->setRam("32GB");
    }

    void buildStorage() override {
        computer_->setStorage("2TB SSD");
    }

    std::unique_ptr<Computer> getResult() override {
        return std::move(computer_);
    }

private:
    std::unique_ptr<Computer> computer_;
};

class Director {
public:
    explicit Director(ComputerBuilder* computerBuilder) : computer_builder_(computerBuilder){
    }

    void construct() const {
        computer_builder_->buildCpu();
        computer_builder_->buildRam();
        computer_builder_->buildStorage();
        computer_builder_->buildGpu();
    }

private:
    ComputerBuilder* computer_builder_;
};

#endif //PS_COMPUTERBUILDER_H