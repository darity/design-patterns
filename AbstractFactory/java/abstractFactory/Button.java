package abstractFactory;
public interface Button {
    void render();
}

class WindowsButton implements Button {

    @Override
    public void render() {
        System.out.println("Rendering Windows button");
    }
}

class MacButton implements Button {

    @Override
    public void render() {
        System.out.println("Rendering Mac button");
    }
}