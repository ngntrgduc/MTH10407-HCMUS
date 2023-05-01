#include <iostream>
#include <string>

using namespace std;

class Book;
class Borrower;
class Library;

class Book {
    string number, author, title;
public: 
    Book(string number="NA", string author="NA", string title="NA") {
        this->setNumber(number);
        this->setAuthor(author);
        this->setTitle(title);
    }
    // Book():Book("NA", "NA", "NA") {}

    void setNumber(string number) { this->number = number; }
    string getNumber() { return this->number; }

    void setAuthor(string author) { this->author = author; }
    string getAuthor() { return this->author; }

    void setTitle(string title) { this->title = title; }
    string getTitle() { return this->title; }

    void display() {
        cout << this->getNumber() << "\n  Book: " << this->getTitle() << "\n  Author: "<< this->getAuthor();
    }

    // void attachBorrower(Borrower borrower) {

    // }

    // void detachBorrower() {

    // }
};

class Library {
    string name;
    Book loanStock;
public:
    Library(string name) {
        this->setName(name);
    }

    void setName(string name) { this->name = name; }

    void registerOneBorrower(string borrowerName) {}
    void addOneBook(Book book) {}
    void displayBookAvailableForLoan() {}
    void displayBooksOnLoan() {}
    void lendOneBook(string catalogueNumber, string borrowerName) {}
    void returnOneBook(string catalogueNumber) {}

};

class Borrower {
    string name;
public:
    Borrower(string name) { this->name = name; }

    void attachBook(Book book) {

    }

    void detachBook(Book book) {

    }
};

int main() {
    Book book("1", "Hi", "Qua mon OOP");
    // Book book("1");
    book.display();
}