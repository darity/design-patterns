public interface Image {
    void display();
}

class RealImage implements Image{

    private final String filename;

    RealImage(String filename){
        this.filename = filename;
        System.out.println("Loading "+filename+" from disk");
    }

    @Override
    public void display() {
        System.out.println("Displaying "+ filename);
    }

}

class ImageProxy implements Image{

    private final String filename;
    private RealImage realImage = null;

    ImageProxy(String filename){
        this.filename = filename;
    }

    @Override
    public void display() {
        if(realImage == null){
            realImage = new RealImage(filename);
        }
        realImage.display();
    }

    static void main() {
        Image imageProxy = new ImageProxy("photo.jpg");

        imageProxy.display();
        imageProxy.display();
    }
}