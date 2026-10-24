import java.util.ArrayList;
import java.util.List;

public interface FileSystemItem {
    int getSize();
    void print(int indent);
}

class File implements FileSystemItem{

    private final String name_;
    private final int size_;

    File(String name, int size){
        this.name_ = name;
        this.size_ = size;
    }

    @Override
    public int getSize() {
        return size_;
    }

    @Override
    public void print(int indent) {
        System.out.println(" ".repeat(indent) + name_ + " (" + size_ + ")");
    }
}

class Folder implements FileSystemItem{

    private final String name_;
    private final List<FileSystemItem> children = new ArrayList<>();

    Folder(String name){
        this.name_ = name;
    }

    public void add(FileSystemItem item){
        children.add(item);
    }

    @Override
    public int getSize() {
        int size = 0;
        for(FileSystemItem item: children){
            size += item.getSize();
        }
        return size;
    }

    @Override
    public void print(int indent) {
        System.out.println(" ".repeat(indent)+name_+"/ ("+getSize()+")");
        for(FileSystemItem item: children){
            item.print(indent+2);
        }
    }



    static void main() {
        Folder root = new Folder("root");
        FileSystemItem fileA = new File("a.txt", 10);
        FileSystemItem fileB = new File("b.txt", 20);

        root.add(fileA);
        root.add(fileB);

        Folder docs = new Folder("docs");
        FileSystemItem fileC = new File("c.txt", 5);

        docs.add(fileC);
        root.add(docs);

        root.print(0);
    }
}