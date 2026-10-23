class NoDiscount implements Discount{
    public double useDiscount(double price){
        return price;
    }
}

class StudentDiscount implements Discount{
    public double useDiscount(double price){
        return price*0.8;
    }
}

class HolidayDiscount implements Discount{
    public double useDiscount(double price){
        return price*0.7;
    }
}

public class Cart {
    private final double price;
    private Discount discount;

    Cart(double price, Discount discount){
        this.price = price;
        this.discount = discount;
    }
    public void setDiscount(Discount discount) {
        this.discount = discount;
    }

    public double totalPrice(){
        return discount.useDiscount(price);
    }

    static void main() {

        Cart cart = new Cart(1000, new NoDiscount());
        System.out.println("No discount price: "+ cart.totalPrice());

        cart.setDiscount(new StudentDiscount());
        System.out.println("Student discount price: "+ cart.totalPrice());

        cart.setDiscount(new HolidayDiscount());
        System.out.println("Holiday discount price: "+ cart.totalPrice());
    }

}

