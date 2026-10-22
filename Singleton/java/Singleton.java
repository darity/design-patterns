public class Singleton {
    private static Singleton instance;
    private int numOfMessages = 0;

    private Singleton() {}

    public static Singleton getInstance(){
        if(instance == null){
            instance = new Singleton();
        }
        return instance;
    }

    public void log(String message){
        numOfMessages++;
        System.out.println("[" + numOfMessages + "] " + message);
    }

    static void main(String[] args) {
        Singleton a = Singleton.getInstance();
        Singleton b = Singleton.getInstance();

        a.log("Program started");
        b.log("Loading data");

        System.out.println(a == b);
    }
}