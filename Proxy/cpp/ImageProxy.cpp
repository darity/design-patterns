#include "ImageProxy.h"

#include <memory>

int main() {
    std::unique_ptr<Image> imageProxy = std::make_unique<ImageProxy>("photo.jpg");

    imageProxy->display();
    imageProxy->display();

}
