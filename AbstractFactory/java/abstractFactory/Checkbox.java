package abstractFactory;
public interface Checkbox {
    void render();
}

class WindowsCheckbox implements Checkbox {

    @Override
    public void render() {
        System.out.println("Rendering Windows checkbox");
    }
}

class MacCheckbox implements Checkbox {

    @Override
    public void render() {
        System.out.println("Rendering Mac checkbox");
    }
}