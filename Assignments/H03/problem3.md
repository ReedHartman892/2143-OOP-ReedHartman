## Problem 3

```cpp
#include <string>
#include <ofstream>
using namespace std;

class BankAccount {
    private:
    string name;
    string accountNumber;
    double balance;

    public:
    // constructors
    BankAccount(){}; // default constructor
    BankAccount(string n, int b) : name(n), balance(b) {}; // parameterized constructor
    // getters
    string getName(){return name;}
    string getAccountNumber(){return accountNumber;}
    double getBalance(){return balance;}

    // setters
    void setName(string n){name = n;}
    void setAccountNumber(string an){accountNumber = an;}
    void setBalance(double b){balance = b;}

    // other methods
    void deposit(double deposited){}
    void withdraw(double withdrawn){}
    void transfer(string an1, string an2, double transfered){}
}
```