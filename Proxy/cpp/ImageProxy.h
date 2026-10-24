#ifndef PS_IMAGEPROXY_H
#define PS_IMAGEPROXY_H
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Image {
public:
    virtual ~Image() = default;
    virtual void display() = 0;
};

class RealImage: public Image {
public:
    explicit RealImage(const std::string& filename) :filename_(filename){
        std::cout<<"Loading "<<filename_<<" from disk"<<std::endl;
    }

    void display() override {
        std::cout<<"Displaying "<<filename_<<std::endl;
    }
private:
    std::string filename_;
};

class ImageProxy: public Image{
public:
    explicit ImageProxy(std::string filename): filename_(std::move(filename)) {}

    void display() override {
        if (realImage == nullptr) {
            realImage = std::make_unique<RealImage>(filename_);
        }

        realImage->display();
    }
private:
    std::unique_ptr<RealImage> realImage = nullptr;
    std::string filename_;
};


#endif //PS_IMAGEPROXY_H