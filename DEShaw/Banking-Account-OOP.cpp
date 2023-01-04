#include <iostream>
#include <string>

class Account {
    private:
        std::string name_;
        double balance_;
        
    public:
        Account(std::string name, double balance): name_(name) balance_(balance) {}
        
        std::string getName() const { return name_; }
        double getBalance() const { return balance_; }
        void deposit(double amount) { balance += amount; }
        bool withdraw(double amount) {
            if(amount > balance_) return false;
            balance_ -= amount;
            return true;
        }
}

class ATM {
    private: 
        Account& account_;
    
    public:
        ATM(Account& account) : account_(account) {}
    
    void checkBalance() {
        std::cout << "Your balance is $" << account_.getBalance() << '\n';
    }
    bool withdraw(double amount) {
        if(account_.withdraw(amount)) {
            std::cout << "Please take your cash.\n";
            return true;
        }
        else {
            cout << "Insufficient funds. \n";
            return false;
        }
    }
    void deposit(double amount) {
        account_.deposit(amount);
        std::cout << "your new balance is $" << account.getBalance() << "\n";
    }
}

int main() {
    Account acc("Jaden Padua", 1000.0);
    ATM atm(acc);
    
    atm.checkBalance();
    atm.withdraw(100);
    
    atm.checkBalance();
    atm.deposit(400);
}
