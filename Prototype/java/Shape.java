public abstract class Shape {
    public Shape(String color){
        this.color = color;
    }

    public abstract Shape clone();
    public abstract void draw();

    public void setColor(String color){
        this.color = color;
    }
    protected String color;

    static void main(String[] args) {
        Circle circle = new Circle("red", 5);
        Rectangle rectangle = new Rectangle("blue", 4,6);

        Shape circleClone = circle.clone();
        Shape rectangleClone = rectangle.clone();

        circleClone.setColor("green");
        rectangleClone.setColor("purple");

        circle.draw();
        circleClone.draw();

        rectangle.draw();
        rectangleClone.draw();
    }
}

class Circle extends Shape{

    private int radius;

    public Circle(String color, int radius){
        super(color);
        this.radius = radius;
    }

    @Override
    public Shape clone() {
        return new Circle(color, radius);
    }

    @Override
    public void draw() {
        System.out.println("Drawing a "+ color +" circle with radius "+ radius);
    }
}

class Rectangle extends Shape{

    private int width;
    private int height;

    public Rectangle(String color, int width, int height){
        super(color);
        this.width = width;
        this.height = height;
    }

    @Override
    public Shape clone() {
        return new Rectangle(color, width, height);
    }

    @Override
    public void draw() {
        System.out.println("Drawing a "+ color +" rectangle "+width+"x"+height);
    }
}

