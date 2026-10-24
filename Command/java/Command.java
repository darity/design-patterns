public interface Command {
    void execute();
    void undo();
}

class LightOnCommand implements Command{

    private LightC light;

    public LightOnCommand(LightC light){
        this.light = light;
    }

    @Override
    public void execute() {
        light.on();
    }

    @Override
    public void undo() {
        light.off();
    }
}

class LightOffCommand implements Command{

    private LightC light;

    public LightOffCommand(LightC light){
        this.light = light;
    }


    @Override
    public void execute() {
        light.off();
    }

    @Override
    public void undo() {
        light.on();
    }
}