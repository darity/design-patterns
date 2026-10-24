#ifndef PS_FILESYSTEMITEM_H
#define PS_FILESYSTEMITEM_H
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// Component
class FileSystemItem {
public:
    virtual ~FileSystemItem() = default;
    virtual int getSize() = 0;
    virtual void print(int indent) = 0;
};

// Leaf
class File: public FileSystemItem{
public:
    File(std::string name, int size):name_(std::move(name)),size_(size){}

    int getSize() override {
        return size_;
    }

    void print(int indent) override {

        std::cout<<std::string(" ", indent);
        std::cout<<name_<<" ("<<size_<<")"<<std::endl;
    }

private:
    std::string name_;
    int size_;
};

// Composite
class Folder: public FileSystemItem {
public:
    explicit Folder(std::string name): name_(std::move(name)){}

    void add(FileSystemItem* item) {
        children.push_back(item);
    }

    int getSize() override {
        int size = 0;
        for (FileSystemItem* item: children) {
            size += item->getSize();
        }
        return size;
    }

    void print(int indent) override {
        std::cout<<std::string(" ", indent);
        std::cout<<name_<<"/ ("<<getSize()<<")"<<std::endl;
        for (FileSystemItem* item: children) {
            item->print(indent+2);
        };
    }
private:
    std::string name_;
    std::vector<FileSystemItem*> children;
};
#endif //PS_FILESYSTEMITEM_H