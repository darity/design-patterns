import java.util.ArrayDeque;
import java.util.Deque;

interface Memento{

}
public class Editor {

    private String text = "";

    private static class EditorMemento implements Memento{
        private final String text;

        private EditorMemento(String text){
            this.text = text;
        }

        String getText(){
            return text;
        }
    }

    void type(String words){
        text+=words;
    }

    Memento save(){
        return new EditorMemento(text);
    }

    void restore(Memento memento){
        text = ((EditorMemento) memento).getText();
    }

    void print(){
        System.out.println("Text: "+text);
    }

}

class History {
    private final Deque<Memento> deque = new ArrayDeque<>();

    public void push(Memento memento){
        deque.push(memento);
    }

    public Memento pop(){
        return deque.pop();
    }

    static void main() {
        Editor editor = new Editor();
        History history = new History();

        editor.type("Hello");
        history.push(editor.save());

        editor.type(" World");
        history.push(editor.save());

        editor.type("!!!");
        editor.print();


        editor.restore(history.pop());
        editor.print();

        editor.restore(history.pop());
        editor.print();
    }
}