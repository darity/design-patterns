class Projector{
    public void turnOn(){
        System.out.println("Projector turned on");
    }

    public void turnOff(){
        System.out.println("Projector turned off");
    }
}

class Light{
    public void dim(){
        System.out.println("Light is dimmed");
    }

    public void turnOn(){
        System.out.println("Light turned on");
    }
}

class Sound{
    public void turnOn(){
        System.out.println("Sound turned on");
    }

    public void turnOff(){
        System.out.println("Sound turned off");
    }

    public void changeSoundLevel(Integer level){
        System.out.println("Sound level: " + level);
    }
}

public class HomeCinema{
    private Projector projector_ = new Projector();
    private Sound sound_ = new Sound();
    private Light light_ = new Light();

    public void startMovie(){
        projector_.turnOn();
        light_.dim();
        sound_.turnOn();
    }

    public void endMovie(){
        light_.turnOn();
        projector_.turnOff();
        sound_.turnOff();
    }

    static void main() {
        HomeCinema homeCinema = new HomeCinema();
        homeCinema.startMovie();
        System.out.println("--- film is rolling ---");
        homeCinema.endMovie();
    }
}