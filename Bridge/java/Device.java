public interface Device {
    void enable();
    void disable();
    void setVolume(int volume);
    int getVolume();
    boolean isEnabled();
}

class Tv implements Device{

    private boolean enabled = false;
    private int volume = 10;

    @Override
    public void enable() {
        enabled = true;
        System.out.println("Tv: enabled");
    }

    @Override
    public void disable() {
        enabled = false;
        System.out.println("Tv: disabled");
    }

    @Override
    public void setVolume(int volume) {
        this.volume = volume;
        System.out.println("Tv: volume set to "+this.volume);
    }

    @Override
    public int getVolume() {
        return volume;
    }

    @Override
    public boolean isEnabled() {
        return enabled;
    }
}

class Radio implements Device{

    private boolean enabled = false;
    private int volume = 10;

    @Override
    public void enable() {
        enabled = true;
        System.out.println("Radio: enabled");
    }

    @Override
    public void disable() {
        enabled = false;
        System.out.println("Radio: disabled");
    }

    @Override
    public void setVolume(int volume) {
        this.volume = volume;
        System.out.println("Radio: volume set to "+this.volume);
    }

    @Override
    public int getVolume() {
        return volume;
    }

    @Override
    public boolean isEnabled() {
        return enabled;
    }
}