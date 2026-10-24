import java.util.ArrayList;
import java.util.List;

public class WeatherStation {
    private final List<Observer> observerList = new ArrayList<>();
    private double currentTemperature = 0;

    public void attach(Observer observer){
        observerList.add(observer);
    }

    public void detach(Observer observer){
        observerList.remove(observer);
    }

    public void setTemperature(double temp){
        currentTemperature = temp;
        for(Observer obs: observerList){
            obs.update(currentTemperature);
        }
    }

    static void main(String[] args) {
        WeatherStation station = new WeatherStation();
        PhoneDisplay phone = new PhoneDisplay();
        WindowDisplay window = new WindowDisplay();

        station.attach(phone);
        station.attach(window);
        station.setTemperature(21.5);

        station.detach(phone);
        station.setTemperature(18.0);
    }
}
