public class User {
    private final String name;
    private final ChatMediator mediator;

    public User(String name, ChatMediator mediator){
        this.name = name;
        this.mediator = mediator;
    }

    public void send(String message){
        System.out.println(name +" sends: "+message);
        mediator.sendMessage(message, this);
    }

    public void receive(String message){
        System.out.println(name+" received: "+message);
    }

    static void main() {
        ChatRoom room = new ChatRoom();
        User ana = new User("Ana", room);
        User marko = new User("Marko", room);
        User jovan = new User("Jovan", room);

        room.addUser(ana);
        room.addUser(marko);
        room.addUser(jovan);

        ana.send("Hello everyone");
        marko.send("Hi Ana");
    }
}
