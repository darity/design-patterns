import java.util.ArrayList;
import java.util.List;

public interface ChatMediator {
    void addUser(User user);
    void sendMessage(String message, User sender);
}

class ChatRoom implements ChatMediator {

    private final List<User> users  = new ArrayList<>();

    @Override
    public void addUser(User user) {
        users.add(user);
    }

    @Override
    public void sendMessage(String message, User sender) {
        for(User usr: users){
            if(usr == sender) continue;
            usr.receive(message);
        }
    }
}