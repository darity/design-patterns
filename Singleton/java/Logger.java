public class Logger {
    private static Logger instance;
    private int numOfMessages = 0;

    private Logger() {}

    public static Logger getInstance(){
        if(instance == null){
            instance = new Logger();
        }
        return instance;
    }

    public void log(String message){
        numOfMessages++;
        System.out.println("[" + numOfMessages + "] " + message);
    }

    static void main(String[] args) {
        Logger a = Logger.getInstance();
        Logger b = Logger.getInstance();

        a.log("Program started");
        b.log("Loading data");

        System.out.println(a == b);
    }
}