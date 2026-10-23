// Creator
public abstract class Logistics {
    abstract Transport createTransport();

    public void planDelivery(){
        System.out.println("Planning delivery...");
        Transport transport  = createTransport();
        transport.deliver();
    }
}

class RoadLogistics extends Logistics{

    @Override
    Transport createTransport() {
        return new Truck();
    }
}

class SeaLogistics extends Logistics{

    @Override
    Transport createTransport() {
        return new Ship();
    }
}

void main() {
    Logistics roadLogistics = new RoadLogistics();
    roadLogistics.planDelivery();

    Logistics seaLogistics = new SeaLogistics();
    seaLogistics.planDelivery();
}