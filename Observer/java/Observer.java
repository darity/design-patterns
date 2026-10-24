public interface Observer {
    void update(double temperature);
}

class PhoneDisplay implements Observer{

    @Override
    public void update(double temperature) {
        System.out.println("Phone display: "+temperature+" C");
    }
}

class WindowDisplay implements Observer{

    @Override
    public void update(double temperature) {
        System.out.println("Window display: "+temperature+" C");
    }
}