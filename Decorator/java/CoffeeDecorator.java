public abstract class CoffeeDecorator implements Coffee{
    protected final Coffee coffee;

    public CoffeeDecorator(Coffee coffee){
        this.coffee = coffee;
    }

    @Override
    public String getDescription(){
        return coffee.getDescription();
    }

    @Override
    public double getCost(){
        return coffee.getCost();
    }

    static void main() {
        Coffee simple = new SimpleCoffee();
        Coffee milk = new MilkDecorator(simple);
        Coffee whip = new WhipDecorator(milk);

        System.out.println(whip.getDescription() + " costs " + whip.getCost());
    }
}

class MilkDecorator extends CoffeeDecorator{

    public MilkDecorator(Coffee coffee) {
        super(coffee);
    }

    @Override
    public String getDescription(){
        return coffee.getDescription() + ", milk";
    }

    @Override
    public double getCost(){
        return coffee.getCost() + 0.5;
    }
}

class WhipDecorator extends CoffeeDecorator{

    public WhipDecorator(Coffee coffee) {
        super(coffee);
    }

    @Override
    public String getDescription(){
        return coffee.getDescription() + ", whip";
    }

    @Override
    public double getCost(){
        return coffee.getCost() + 0.7;
    }
}