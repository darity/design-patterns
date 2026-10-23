public abstract class Beverage {
    //Template Method: the order of steps is fixed
    public void prepare(){
        boilWater();
        brew();
        pourIntoCup();
        addCondiment();
    }

    void boilWater(){
        System.out.println("Boiling water...");
    }

    void pourIntoCup(){
        System.out.println("Pouring into cup...");
    }

    abstract void brew();
    abstract void addCondiment();
}

class Tea extends Beverage{

    @Override
    void brew(){
        System.out.println("Steeping the tea bag...");
    }

    @Override
    void addCondiment() {
        System.out.println("Adding lemon...");
    }

}

class Coffee extends Beverage{

    @Override
    void brew() {
        System.out.println("Dripping the coffee");
    }

    @Override
    void addCondiment() {
        System.out.println("Adding milk...");
    }
}

void main() {
    Beverage tea = new Tea();
    System.out.println("------Tea------");
    tea.prepare();

    Beverage coffee = new Coffee();
    System.out.println("-----Coffee-----");
    coffee.prepare();
}
