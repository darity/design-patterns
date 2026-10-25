package abstractFactory;
public class Application {

    private final GUIFactory factory;
    private Button button;
    private Checkbox checkbox;

    public Application(GUIFactory factory){
        this.factory = factory;
    }

    public void createUI(){
        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    public void render(){
        button.render();
        checkbox.render();
    }

    static void main() {
        Application appW = new Application(new WindowsFactory());
        appW.createUI();
        appW.render();

        Application appM = new Application(new MacFactory());
        appM.createUI();
        appM.render();
    }
}
