#include "PaymentProcessor.h"

#include <memory>

int main() {
    auto oldBankApi = std::make_unique<OldBankApi>();
    auto bankAdapter = std::make_unique<BankAdapter>(oldBankApi.get());
    auto checkout = std::make_unique<Checkout>(bankAdapter.get());

    checkout->buy(12.50);
}