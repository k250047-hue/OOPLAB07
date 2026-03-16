#include <iostream>
using namespace std;

class Currency {
private:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    double getAmount() { return amount; }
    string getCurrencyCode() { return currencyCode; }
    string getCurrencySymbol() { return currencySymbol; }
    double getExchangeRate() { return exchangeRate; }

    void convertToBase() {
        double baseAmount = amount * exchangeRate;
        cout << "Amount in base currency (USD): $" << baseAmount << endl;
    }

    void convertTo(double targetRate, string targetSymbol) {
        double converted = amount * (targetRate / exchangeRate);
        cout << "Converted amount: " << targetSymbol << converted << endl;
    }

    void displayCurrency() {
        cout << "Currency: " << currencyCode << endl;
        cout << "Symbol: " << currencySymbol << endl;
        cout << "Amount: " << currencySymbol << amount << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void convertToBase() {
        cout << "Dollar to base (USD): $" << getAmount() << endl;
    }

    void displayCurrency() {
        cout << "Dollar Amount: $" << getAmount() << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    void convertToBase() {
        double baseAmount = getAmount() * getExchangeRate();
        cout << "Euro to base (USD): $" << baseAmount << endl;
    }

    void displayCurrency() {
        cout << "Euro Amount: €" << getAmount() << endl;
    }
};

class PKR : public Currency {
public:
    PKR(double amt) : Currency(amt, "PKR", "Rs", 0.0058) {}

    void convertToBase() {
        double baseAmount = getAmount() * getExchangeRate();
        cout << "PKR to base (USD): $" << baseAmount << endl;
    }

    void displayCurrency() {
        cout << "PKR Amount: Rs" << getAmount() << endl;
    }
};

int main() {
    Dollar d(100);
    Euro e(50);
    PKR r(5000);

    d.displayCurrency();
    d.convertToBase();

    e.displayCurrency();
    e.convertToBase();
    e.convertTo(d.getExchangeRate(), "$");

    r.displayCurrency();
    r.convertToBase();
    r.convertTo(e.getExchangeRate(), "€");

    return 0;
}