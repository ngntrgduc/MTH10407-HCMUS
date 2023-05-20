#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book;
class BorrowerRecord;
class Library;

class Book {
    string number;
    string author;
    string title;
    BorrowerRecord* borrower;
public: 
    Book(string number="NA", string author="NA", string title="NA") {
        this->setNumber(number);
        this->setAuthor(author);
        this->setTitle(title);
        this->setBorrower(NULL);
    }
    Book():Book("NA", "NA", "NA") {}

    void setNumber(string number) {
        this->number = number;
    }

    string getNumber() {
        return this->number;
    }

    void setAuthor(string author) {
        this->author = author;
    }

    string getAuthor() {
        return this->author;
    }

    void setTitle(string title) {
        this->title = title;
    }
    
    string getTitle() {
        return this->title;
    }

    void display() {
        cout << "- Number: " << this->getNumber() 
        << "\n  Book: " << this->getTitle() 
        << "\n  Author: "<< this->getAuthor() << '\n';
    }

    void setBorrower(BorrowerRecord *borrower) {
        this->borrower = borrower;
    }

    void attachBorrower(BorrowerRecord *borrower) {
        this->setBorrower(borrower);
    }

    void detachBorrower() {
        this->setBorrower(NULL);
    }

    BorrowerRecord* getBorrower() {
        return this->borrower;
    }
};

class BorrowerRecord {
    string name;
    vector<Book*> books;
public:
    BorrowerRecord(string name, vector<Book*> books) {
        this->setName(name);
        this->setBooks(books);
    }
    BorrowerRecord(string name) : BorrowerRecord(name, vector<Book*>()) {}

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    void setBooks(vector<Book*> books) {
        this->books = books;
    }

    vector<Book*> getBooks() {
        return this->books;
    }

    void display() {
        cout << "Borrower: " << this->getName() << '\n';
    }

    void attachBook(Book *book) {
        this->books.push_back(book);
    }

    void detachBook() {
        this->books.pop_back();
    }
};

class Library {
    string name;
    vector<Book*> books;
    vector<BorrowerRecord*> borrowers;
public:
    Library(string name) {
        this->setName(name);
        // this->books = vector<Book*>;
        // this->borrowers = vector<BorrowerRecord>;
    }
    Library() : Library("NA") {}

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }    

    void display() {
        cout << this->getName() << "\nBooks:\n";
        for (int i = 0; i < books.size(); i++)
            books[i]->display();
    }

    void addOneBook(Book *book) {
        // cout << "Book: " << book->getTitle() << " was added to the library" << endl;
        this->books.push_back(book);
    }

    void registerOneBorrower(string name) {
        BorrowerRecord *borrower = new BorrowerRecord(name);
        this->borrowers.push_back(borrower);
    }

    void displayBooksAvailableForLoan() {
        cout << "\nBooks available for loan:\n";
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getBorrower() == NULL)
                books[i]->display();
        }
    }

    void displayBooksOnLoan() {
        cout << "\nBooks on loan:\n";
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getBorrower() != NULL) {
                cout << "Borrower: " << books[i]->getBorrower()->getName() << '\n';
                books[i]->display();
            }
        }
    }

    void lendOneBook(string number, string name) {
        Book* book = NULL;
        for (int i = 0; i < this->books.size(); i++)
            if (this->books[i]->getNumber() == number) {
                book = this->books[i];
                break;
            }
        if (book == NULL) {
            cout << "\nBook " << number << " not exists\n";
            return;
        } else {
            if (book->getBorrower() != NULL) {
                cout << "\nBook " << number << " already have borrower "
                            << book->getBorrower()->getName() << ", not available for loan\n";
                return;
            }
        }

        BorrowerRecord* borrower = NULL;
        for (int i = 0; i < this->borrowers.size(); i++)
            if (this->borrowers[i]->getName() == name) {
                borrower = this->borrowers[i];
                break;
            }
        if (borrower == NULL) {
            cout << "\nBorrower " << name << " not exists\n";
            return;
        }
        
        book->attachBorrower(borrower);
        borrower->attachBook(book);
    }

    void returnOneBook(string number) {
        bool bookAvailable = false;
        for (int i = 0; i < this->books.size(); i++) {
            if (books[i]->getNumber() == number) {
                bookAvailable = true;
                BorrowerRecord *borrower = this->books[i]->getBorrower();
                cout << "\nBorrower: " << borrower->getName() << 
                        " return book " << books[i]->getNumber() << '\n'; 
                borrower->detachBook();
                this->books[i]->detachBorrower();
                break;
            }
        }

        if (!bookAvailable) 
            cout << "\nBook " << number << " not exists\n";
    }
};


int main() {
    Book book1("1", "Author", "Qua mon OOP");
    Book book2("2", "Author", "Bi kip OOP");
    Book book3("3", "Author", "Danh bai OOP");

    Library library("HCMUS - Library");
    library.addOneBook(&book1);
    library.addOneBook(&book2);
    library.addOneBook(&book3);
    library.display();
    library.registerOneBorrower("Nguyen Trung Duc");
    library.registerOneBorrower("Alice");
    library.registerOneBorrower("Bob");
    library.lendOneBook("3", "Nguyen Trung Duc");
    library.lendOneBook("1", "Alice");
    library.lendOneBook("2", "Bob");
    library.displayBooksAvailableForLoan();
    library.displayBooksOnLoan();
    library.lendOneBook("1", "Nguyen Trung Duc");
    library.returnOneBook("1");
    library.lendOneBook("1", "Nguyen Trung Duc");
    library.displayBooksOnLoan();
    library.displayBooksAvailableForLoan();
    library.returnOneBook("1");
    library.displayBooksAvailableForLoan();
    library.lendOneBook("1", "Duc");
}