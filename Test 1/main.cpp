#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account;
class AccountOwner;

class Account {
    int id;
    int balance;
    vector<AccountOwner*> accountOwners;
public:
    Account(int id, int balance) {
        this->setId(id);
        this->setBalance(balance);
    }
    Account() : Account(0, 0) {}

    int getId() {
        return this->id;
    }

    void setId(int id) {
        this->id = id;
    }

    int getBalance() {
        return this->balance;
    }

    void setBalance(int balance) {
        this->balance = balance;
    }

    void display() {
        cout << "- Account id: " << this->getId() << 
                ", Balance of account: " << this->getBalance() << '\n';
    }
    
    void setOwner(AccountOwner *owner) {
        this->accountOwners.push_back(owner);
    }

    void displayOwners(); // Se cai dat sau vi ham getName() cua lop AccountOwnder chua khai bao
};

class AccountOwner {
    string name;
    vector<Account*> accounts;
public:
    AccountOwner(string name, vector<Account*> accounts) {
        this->setName(name);
        this->setAccounts(accounts);
    }
    AccountOwner(string name) : AccountOwner(name, vector<Account*>()) {}

    void setAccounts(vector<Account*> accounts) {
        this->accounts = accounts;
    }

    vector<Account*> getAccounts(vector<Account*> accounts) {
        return this->accounts;
    }

    string getName() {
        return this->name;
    }

    void setName(string name) {
        this->name = name;
    }

    void display() {
        cout << "Name of the account owner: " << this->getName() << '\n';
    }

    // Vi register la tu khoa mac dinh cua C++ nen khong the cai ham register()
    void registerAccount(Account *account) {
        this->accounts.push_back(account);
        account->setOwner(this);
    }

    void displayAccounts() {
        if (this->accounts.size() == 0) {
            cout << "Account Owner " << this->getName() << " doesn't has any account\n";
        } else {
            cout << "Account Owner " << this->getName() << " has :\n";
            for (int i = 0; i < this->accounts.size(); i++) {
                accounts[i]->display(); 
            }
        }
    }
};

void Account::displayOwners() {
    if (accountOwners.size() == 0) {
        cout << "Account with id " << this->getId() << " has no owner\n";
    } else {
        cout << "Account with id " << this->getId() << " has owners: \n";
        for (int i = 0; i < this->accountOwners.size(); i++) {
            cout << "- " << this->accountOwners[i]->getName() << "\n";
        }    
    }
}

int main() {
    // Create Account
    Account a1(1, 100000);
    Account a2(2, 200000);
    Account a3(3, 300000);
    a1.display();
    a2.display();
    a3.display();

    // Display Account Owner
    AccountOwner user("Nguyen Trung Duc");
    AccountOwner user2("Alice");
    user.display();
    user2.display();

    // Register Nguyen Trung Duc with accout 1 & 3
    user.registerAccount(&a1);
    user.registerAccount(&a3);
    user.displayAccounts();
    user2.displayAccounts();

    // Display owners of all accounts
    a1.displayOwners();
    a2.displayOwners();
    a3.displayOwners();

    // Register Alice with account 1
    user2.registerAccount(&a1);
    a1.displayOwners();
    return 0;
}