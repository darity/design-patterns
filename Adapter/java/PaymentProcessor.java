// Target
public interface PaymentProcessor {
    void pay(double amountInEuros);
}

// Adaptee
class OldBankApi{
    public void makePayment(int amountInCents){
        System.out.println("Old bank API: paid "+amountInCents+" cents");
    }
}

// Adapter
class BankAdapter implements PaymentProcessor{
    public BankAdapter(OldBankApi oldBankApi){
        this.oldBankApi = oldBankApi;
    }

    @Override
    public void pay(double amountInEuros) {
        oldBankApi.makePayment((int) Math.round(amountInEuros*100));
    }

    private OldBankApi oldBankApi;
}

// Client
class Checkout{

    private PaymentProcessor paymentProcessor;

    public Checkout(PaymentProcessor paymentProcessor){
        this.paymentProcessor = paymentProcessor;
    }

    public void buy(double price){
        System.out.println("Processing purchase...");
        paymentProcessor.pay(price);
    }

    static void main() {
        OldBankApi oldBankApi = new OldBankApi();
        BankAdapter bankAdapter = new BankAdapter(oldBankApi);
        Checkout checkout = new Checkout(bankAdapter);

        checkout.buy(12.50);
    }
}