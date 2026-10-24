#include "FileSystemItem.h"

#include <memory>

int main() {
    auto root = std::make_unique<Folder>("root");
    auto fileA = std::make_unique<File>("a.txt", 10);
    auto fileB = std::make_unique<File>("b.txt", 20);

    root->add(fileA.get());
    root->add(fileB.get());

    auto docs = std::make_unique<Folder>("docs");
    auto fileC = std::make_unique<File>("c.txt", 5);

    docs->add(fileC.get());
    root->add(docs.get());

    root->print(0);

}
