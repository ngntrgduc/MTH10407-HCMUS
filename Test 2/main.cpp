#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Product {
    string id;
    string name;
    float price;
public:
    Product (string id, string name, float price) {
        this->setId(id);
        this->setName(name);
        this->setPrice(price);
    }

    void setId(string id) {
        this->id = id;
    }

    string getId() {
        return this->id;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    void setPrice(float price) {
        this->price = price;
    }

    float getPrice() {
        return this->price;
    }

    virtual void display() {
        cout << "- ID: " << this->getId() << "\n"
             << "- Name: " << this->getName() << "\n"
             << "- Price: " << this->getPrice() << "\n";
    }
};

class Book: public Product {
    string title;
    string author;
public:
    Book (string id, string name, float price, string title, string author) 
        : Product(id, name, price){
        this->setTitle(title);
        this->setAuthor(author);
    }

    void setTitle(string title) {
        this->title = title;
    }

    string getTitle() {
        return this->title;
    }

    void setAuthor(string author) {
        this->author = author;
    }

    string getAuthor() {
        return this->author;
    }

    void display() {
        cout << "Thong tin cua sach: \n";
        Product::display();
        cout << "- Title of book: " << this->getTitle() << "\n"
             << "- Author: " << this->getAuthor() << "\n";
    }
};

class Pen: public Product {
    string type;
    string color;
public:
    Pen (string id, string name, float price, string type, string color) 
        : Product(id, name, price){
        this->setType(type);
        this->setColor(color);
    }

    void setType(string type) {
        this->type = type;
    }

    string getType() {
        return this->type;
    }

    void setColor(string color) {
        this->color = color;
    }

    string getColor() {
        return this->color;
    }

    void display() {
        cout << "Thong tin cua cay but: \n";
        Product::display();
        cout << "- Type of pen: " << this->getType() << "\n"
             << "- Color: " << this->getColor() << "\n";
    }
};

class Item {
    Product *product;
    int number;
public:
    Item(Product *product, int number) {
        this->setProduct(product);
        this->setNumber(number);
    }

    void setProduct(Product *product) {
        this->product = product;
    }

    Product *getProduct() {
        return this->product;
    }

    void setNumber(int number) {
        this->number = number;
    }

    int getNumber() {
        return this->number;
    }
};

class Cart {
    string id;
    vector<Item> items;
public:
    Cart(string id) {
        this->setId(id);
        cout << "\nDa tao gio hang voi ma so " << this->getId() << "\n";
    }

    void setId(string id) {
        this->id = id;
    }

    string getId() {
        return this->id;
    }

    void setItems(vector<Item> items) {
        this->items = items;
    }

    vector<Item> getItems() {
        return this->items;
    }

    void addItem(Product *p, int number) {
        Item item(p, number);
        this->items.push_back(item);
        cout << "Da them " << number << " " << p->getName() << " vao gio hang\n";
    }

    void display() {
        cout << "Thong tin cua gio hang ma so " << this->getId() << ":\n";
        for (int i = 0; i < this->getItems().size(); i++) {
            cout << "San pham: " << this->getItems()[i].getProduct()->getName() << "\n";
            this->getItems()[i].getProduct()->display();
            cout << "* So luong: " << this->getItems()[i].getNumber() << "\n";
        }
    }
};

int main() {
    Book book("001", "Book", 100000, "Lap trinh OOP", "HCMUS"); 
    book.display();

    Pen pen("004", "Pen", 10000, "ballpoint", "blue");
    pen.display();

    Cart cart("ID-001");
    cart.addItem(&book, 1);
    cart.addItem(&pen, 2);
    cart.display();
}