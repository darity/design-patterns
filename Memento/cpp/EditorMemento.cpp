#include "EditorMemento.h"

#include <memory>

int main() {
    auto editor = std::make_unique<Editor>();
    auto history = std::make_unique<History>();

    editor->type("Hello");
    history->push(editor->save());

    editor->type(" World");
    history->push(editor->save());

    editor->type("!!!");
    editor->print();

    editor->restore(history->pop());
    editor->print();

    editor->restore(history->pop());
    editor->print();
}
