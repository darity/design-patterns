// Product
public interface Transport {
    void deliver();
}

class Truck implements Transport{

    @Override
    public void deliver() {
        System.out.println("Delivering by land in a truck");
    }
}

class Ship implements Transport{

    @Override
    public void deliver() {
        System.out.println("Delivering by sea in a ship");
    }
}
