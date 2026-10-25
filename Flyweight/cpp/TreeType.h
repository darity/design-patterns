#ifndef PS_TREETYPE_H
#define PS_TREETYPE_H
#include <map>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// Flyweight
class TreeType {
public:
    TreeType(std::string name, std::string color):
    name_(std::move(name)), color_(std::move(color)){}

    void draw(const int x,const int y) const{
        std::cout<<"Drawing "<<name_<<" tree ("<<color_
        <<") at ("<<x<<","<<y<<")"<<std::endl;
    }
private:
    const std::string name_, color_;
};

// Flyweight factory
class TreeFactory {
public:
    TreeType* getTreeType(const std::string& name, const std::string& color) {
        auto t = types_.find(name);
        if (t==types_.end()) {
            t = types_.emplace(name,std::make_unique<TreeType>(name, color)).first;
        }
        return t->second.get();
    }

    size_t getCount() const{
        return types_.size();
    }

private:
    std::map<std::string, std::unique_ptr<TreeType>> types_;
};

// Context
class Tree {
public:
    Tree(int x, int y, TreeType* type):
    x_(x), y_(y), type_(type) {}

    void draw() const {
        type_->draw(x_,y_);
    }
private:
    int x_, y_;
    TreeType* type_;
};

// Client
class Forest {
public:
    Forest() {
        factory_ = std::make_unique<TreeFactory>();
    }
    void plantTree(int x, int y, const std::string& name, const std::string& color) {
        trees.push_back(std::make_unique<Tree>(x, y, factory_->getTreeType(name, color)));
    }

    void draw() const {
        for (const auto & tree : trees) {
            tree->draw();
        }
    }

    size_t forestSize() const {
        return factory_->getCount();
    }

private:
    std::vector<std::unique_ptr<Tree>> trees;
    std::unique_ptr<TreeFactory> factory_;
};

#endif //PS_TREETYPE_H