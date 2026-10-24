public class RemoteControlB {

    protected final Device device;

    public RemoteControlB(Device device){
        this.device = device;
    }

    public void togglePower(){
        if (device.isEnabled()) {
            device.disable();
        } else {
            device.enable();
        }
    }

    void volumeUp(){
        device.setVolume(device.getVolume()+10);
    }

    void volumeDown(){
        device.setVolume(device.getVolume()-10);
    }
}

class AdvancedRemoteControlB extends RemoteControlB{

    public AdvancedRemoteControlB(Device device) {
        super(device);
    }

    public void mute(){
        device.setVolume(0);
    }

    static void main() {
        RemoteControlB remote = new RemoteControlB(new Tv());
        AdvancedRemoteControlB advancedRemote = new AdvancedRemoteControlB(new Radio());

        remote.togglePower();
        remote.volumeUp();

        advancedRemote.togglePower();
        advancedRemote.mute();
    }
}