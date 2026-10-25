#ifndef PS_EDITORMEMENTO_H
#define PS_EDITORMEMENTO_H
#include <iostream>
#include <string>
#include <stack>

class Editor;

class EditorMemento {
public:
    friend class Editor;
private:
    explicit EditorMemento(std::string text): text_(std::move(text)){}

    std::string getText() const{
        return text_;
    }

    std::string text_;
};

// Originator
class Editor {
public:
    void type(const std::string& words) {
        text+=words;
    }

    EditorMemento save() const {
        return EditorMemento(text);
    }

    void restore(const EditorMemento& memento) {
        text = memento.getText();
    }

    void print() const {
        std::cout<<"Text: "<<text<<std::endl;
    }
private:
    std::string text;
};

// Caretaker
class History {
public:
    void push(EditorMemento memento) {
        mementos.push(std::move(memento));
    }

    EditorMemento pop() {
        EditorMemento memento = std::move(mementos.top());
        mementos.pop();
        return memento;
    }
private:
    std::stack<EditorMemento> mementos;
};


#endif //PS_EDITORMEMENTO_H