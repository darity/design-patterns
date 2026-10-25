import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TreeType {
    private final String name;
    private final String color;

    public TreeType(String name, String color){
        this.name = name;
        this.color = color;
    }

    public void draw(int x, int y){
        System.out.println("Drawing "+name+" tree ("+color+") at ("+x+","+y+")");
    }
}

class TreeFactory{
    private final Map<String, TreeType> trees = new HashMap<>();

    public TreeType getTreeType(String name, String color){
        trees.putIfAbsent(name, new TreeType(name, color));
        return trees.get(name);
    }

    public int getCount(){
        return trees.size();
    }
}

class Tree{
    private final int x;
    private final int y;
    private final TreeType type;

    public Tree(int x, int y, TreeType type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }

    public void draw(){
        type.draw(x,y);
    }
}

class Forest{
    private final List<Tree> trees = new ArrayList<>();
    private final TreeFactory factory = new TreeFactory();

    public void plantTree(int x, int y, String name, String color){
        trees.add(new Tree(x, y, factory.getTreeType(name, color)));
    }

    public void draw(){
        for(Tree t: trees){
            t.draw();
        }
    }

    int forestSize(){
        return factory.getCount();
    }

    static void main() {
        Forest forest = new Forest();
        forest.plantTree(1,2,"Oak", "Green");
        forest.plantTree(3, 4, "Pine", "DarkGreen");
        forest.plantTree(5, 6, "Oak", "Green");
        forest.plantTree(7, 8, "Oak", "Green");

        forest.draw();

        System.out.println("Forest size: "+forest.forestSize());
    }
}