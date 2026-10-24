public class RemoteControl {

    private Command command;
    private Command lastCommand;

    public void setCommand(Command command){
        this.command = command;
    }

    public void pressButton(){
        command.execute();
        lastCommand = command;
    }

    public void pressUndo(){
        lastCommand.undo();
    }

    static void main() {
        LightC light = new LightC();
        LightOnCommand lightOnCommand = new LightOnCommand(light);
        LightOffCommand lightOffCommand = new LightOffCommand(light);

        RemoteControl remoteControl = new RemoteControl();

        remoteControl.setCommand(lightOnCommand);
        remoteControl.pressButton();
        remoteControl.setCommand(lightOffCommand);
        remoteControl.pressButton();

        remoteControl.pressUndo();
    }
}
