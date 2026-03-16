#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNo, string name, double bal, string type) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
        accountType = type;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance" << endl;
    }

    void calculateInterest() {
        cout << "General account interest calculation" << endl;
    }

    void printStatement() {
        cout << "Account Statement" << endl;
        cout << "Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, string name, double bal, double rate, double minBal)
        : Account(accNo, name, bal, "Savings") {
        interestRate = rate;
        minimumBalance = minBal;
    }

    void calculateInterest() {
        double interest = balance * interestRate;
        balance += interest;
    }

    void withdraw(double amount) {
        if (balance - amount >= minimumBalance)
            balance -= amount;
        else
            cout << "Minimum balance requirement not met" << endl;
    }

    void printStatement() {
        cout << "Savings Account Statement" << endl;
        cout << "Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal, "Checking") {}

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Overdraft not allowed" << endl;
    }

    void printStatement() {
        cout << "Checking Account Statement" << endl;
        cout << "Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(int accNo, string name, double bal, double rate, string maturity)
        : Account(accNo, name, bal, "Fixed Deposit") {
        fixedInterestRate = rate;
        maturityDate = maturity;
    }

    void calculateInterest() {
        double interest = balance * fixedInterestRate;
        balance += interest;
    }

    void withdraw(double amount) {
        cout << "Withdrawal not allowed before maturity date" << endl;
    }

    void printStatement() {
        cout << "Fixed Deposit Account Statement" << endl;
        cout << "Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Interest Rate: " << fixedInterestRate << endl;
    }
};

int main() {

    SavingsAccount s1(100, "Hussain", 6000, 0.06, 1000);
    CheckingAccount c1(101, "Aisha", 4000);
    FixedDepositAccount f1(102, "Talha", 10000, 0.09, "12-11-2030");

    s1.calculateInterest();
    c1.withdraw(500);
    f1.calculateInterest();

    s1.printStatement();
    cout << endl;

    c1.printStatement();
    cout << endl;

    f1.printStatement();

    return 0;
}