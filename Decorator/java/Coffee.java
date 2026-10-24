public interface Coffee {
    String getDescription();
    double getCost();
}

class SimpleCoffee implements Coffee{

    @Override
    public String getDescription() {
        return "Simple coffee";
    }

    @Override
    public double getCost() {
        return 2.0;
    }
}