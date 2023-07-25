# OOP
Một vài note của tui khi tự học OOP.

**Note**: Note này có rất nhiều bủh bủh lmao.

## Resources
- https://www.learncpp.com/, chapter 13. 14. 16, 17, 18, 19
- Phương pháp lập trình hướng đối tượng - *Trần Đan Thư, Đinh Bá Tiến, Nguyễn Tấn Trần Minh Khang.*
- Và rất nhiều lần fix bug.

## C++
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
```
## Access spectifiers

- `public`: can be accessed **by anyone**.
- `private`: can **only be accessed by other members of the class or friends**.
- `protected`: can be **accessed by other members of the class, friends, and derived classes.**

## Abstraction
Displaying only essential information and hiding the details

## Encapsulation
The process of keeping the details about how an object is implemented hidden away from users of the object. Instead, users of the object access the object through a public interface. In this way, users are able to use the object without having to understand how it is implemented.
**Benefit**: encapsulated classes are easier to use and reduce the complexity of programs, easier to change, to debug, help protect data and prevent misuse.
## Polymorphism
### Virtual functions
- A **virtual function** is a special type of function that, when called, **resolves to the most-derived version** of the function that exists between the base and derived class. This capability is known as **polymorphism**. A derived function is considered a match if it has the same signature as the base version of the function. Such functions are called **overrides**.
```cpp
class Base {
public:
    virtual std::string getName() const {
        return "Base"; 
    }
};

class Derived: public Base {
public:
    virtual std::string getName() const {
        return "Derived"; 
    }
};

int main() {
    Derived derived {};
    Base& rBase{ derived };
    std::cout << "rBase is " << rBase.getName(); //rBase is Derived
}
```
- Virtual function resolution only works when a member function is called through a pointer or reference to a class type object.
- If a function is virtual, all matching overrides in derived classes are **implicitly virtual**.
- There may be cases where you don’t want someone to be able to override a virtual function, or inherit from a class. The **`final specifier`** can be used to tell the compiler to enforce this. 
```cpp
class Bruh {};
class BruhBruh final : public Bruh {};
class BruhBruhBruh : public BruhBruh {}; // error
```

## Inheritance 
The class being inherited from is called the **parent class**, **base class**, or **superclass**, and the class doing the inheriting is called the **child class**, **derived class**, or **subclass**.

|Access specifier in base class|Access specifier when inherited publicly|Access specifier when inherited privately (rarely used)|Access specifier when inherited protectedly (almost never used)|
|-|-|-|-|
|Public|Public|Private|Protected|
|Protected|Protected|Private|Protected|
|Private|Inaccessible|Inaccessible|Inaccessible|

### Pure virtual function
```cpp 
class Bruh {
public:
    virtual void bruh() = 0; // a pure virtual function
};
```
Any class with one or more pure virtual functions becomes an **abstract base class**

### Interface classes
An interface class is a class that has **no member variables**, and where **all of the functions are pure virtual**.
```cpp
class IBruh {
public:
    virtual void Bruh() = 0;
    virtual ~IBruh() {} // virtual destructor
};
```

## Constructors

```cpp
Bruh();
```

Same name as the class; Can take arguments; Have no return type

### Copy constructor

```cpp
// Syntax: Bruh(const Bruh& bruh)
// Bruh(const Bruh& bruh): bruh.lmao{lmao} {}
class Bruh {
    int lmao;
public:
    Bruh(int lmao) {
        lmao = lmao; 
    }
    // Copy constructor
    Bruh(const Bruh& bruh) { 
        lmao = bruh.lmao; // ...
    } 
};
```

Nếu kiểu dữ liệu của các thành phần dữ liệu bên trong 1 lớp đối tượng **không phải là kiểu dữ liệu con trỏ** thì **không cần copy constructor**.

## Destructors

```cpp
~Bruh();
```

Same name as the class, preceded by `~`; **Can't** take arguments; Has **no return type**

## Member initializer lists

```cpp
private:
    int a {};
    double b {};
public:
    // Initialize member variables
    Bruh() : a{ 1 }, b{ 2.0 } {} // No need for assignment here 
```

- No longer need to do the assignments in the constructor body, since the initializer list replaces that functionality. Also the initializer list doesn't end in a semicolon.
- Variables in the initializer list are not initialized in the order that they are specified in the initializer list. They are initialized in the order in which they are **declared in the class**.

## Delegating constructors (constructor chaining)

Constructors are allowed to **call other constructors from the same class**.

```cpp
public:
    A() { 
        // code to do A 
    }
    B(int value): A{} // use A() default constructor to do A
    { 
        // code to do B 
    }
```

## *`*this`* pointer
- **this pointer** is a **hidden const pointer** (can change the value of the object it points to, but can not make it point to something else) that holds the **address of the object** the member function was **called on**
- All **non-static member** functions have a **"this" pointer**
- “**this**” always points to the object being operated on, and because "**this**" is just a function parameter, it doesn’t add any memory usage to class
- Use to make functions **chainable**. Most often used when overloading operators for classes
```cpp
class Calc {
private:
    int m_value{};
public:
    Calc& add(int value) { 
        m_value += value; 
        return *this; 
    }
    Calc& sub(int value) {
        m_value -= value; 
        return *this;
    }
    Calc& mult(int value) {
        m_value *= value; 
        return *this;
    }
    int get() {
        return m_value;
    }
};
int main() {
    Calc calc{};
    calc.add(5).sub(3).mult(4); // returning *this, reference to calc
    std::cout << calc.get(); // = 8
}
```
  
## Function overloading

Create multiple functions with the **same name**, so long as each identically named function has **different parameter** types (or the functions can be otherwise differentiated).
```cpp
void Bruh(int bruh) {
    cout << "Int bruh";
}
void Bruh(double bruh) {
    cout << "Double bruh";                   
}
```

## Operator overloading
```cpp
friend Bruh& operator+(const Bruh& bruh, const Bruh& lmao) {}
Bruh& operator+=(Bruh& bruh) {} // as a member function
friend bool operator==(const Bruh& bruh, const Bruh& lmao) {}
friend ostream& operator<<(ostream &out, const Bruh& bruh) {
    out << "lmao"; 
    return out; // return std::ostream so can chain calls to operator<<
}
```
- Almost any existing operator in C++ can be overloaded. The exceptions are: conditional (`?:`), `sizeof`, scope (`::`), member selector (`.`), pointer member selector (`.*`), `typeid`, and the casting operators.
- **Can't be overloaded as a friend function**: The assignment (`=`), subscript (`[]`), function call (`()`), and member selection (`->`) operators

## Static
Static member variables are shared by all objects of the class

```cpp
class Bruh {
private:
    static int count; // Biến đếm số lượng đối tượng của class Bruh
public:
    static int show() { return count; }
    Bruh() { count++; }
    ~Bruh() { count--; }
};
int Bruh::count = 0;
int main() { 
    Bruh a, b; 
    // Bruh::show() will return 2 
}
```
## Const member function
- Is a member function that guarantees it will not modify the object or call any **non-const** member functions (as they may modify the object).
- append the `const` keyword to the function prototype, after the parameter list, before the function body
```cpp
int Bruh(int lmao) const {}
```
- For member functions defined outside of the class definition, the const keyword must be used on both the **function prototype** in the class definition and on the **function definition**
```cpp
class Bruh {
public:
    int lmao() const; 
};
int Bruh::lmao() const {
    return lmao;
}
```
- Best practice: ***Make any member function that does not modify the state of the class object const, so that it can be called by const objects.***
```cpp
class Bruh {
public:
    void lmao() {}
    void lmaoConst() const {}
};
void Something(Bruh a, const Bruh& b) {
    a.lmao(); // gud, a là biến bình thường
    a.lmaoConst(); // gud, a là biến bình thường
    b.lmao(); //bủh, b là tham chiếu const, lmao() là non-const
    b.testConst(); // gud, lmaoConst() là phương thức const
}
```
## Friend functions
- A **friend function** is a function that can access the private members of a class as though it was a member of that class
```cpp
class A {
private:
    int value { 0 };
public:
    void add(int val) { value += val; }
    friend void reset(A& a); // Make reset() a friend of this class
};
// reset() is now a friend of the A class
void reset(A& a) {
    a.value = 0; // And can access the private data of A objects
}
int main() {
    A a; a.add(5); // add 5 to a
    reset(a); // reset a to 0
}
```
- It is also possible to make an entire class a friend of another class. This gives all of the members of the friend class access to the private members of the other class
- Note that making a specific **member function a friend** requires the full definition for the class of the member function to have been seen first
- Be careful when using friend functions and classes, because it allows the friend function or class to **violate encapsulation**. If the details of the class change, the details of the friend will also be forced to change. 

## Anonymous class objects
```cpp
Bruh bruh{ 2 }; // normal variable
Bruh{ 0 }; // anonymous object
Bruh bruh(Bruh& lmao) {
	return {lmao}; // return anonymous Bruh value
}
```
Anonymous objects are primarily used either to pass or return values without having to create lots of temporary variables.


## Templates

```cpp
template <typename T>
T add(T a, T b) { return a + b; }
int main() {
    int a = 2, b = 4;
    string c = "hello", d = " world";
    cout << add(a, b); // 6
    cout << add(c, d); // hello world
}
```

```cpp
template <typename T>
class Bruh {
public:
    Bruh() {}
    T lmao(T lmao) {
        return lmao;
    }
};
int main() {
    Bruh<int> a;
    cout << a.lmao(2); // 2
    Bruh<string> b;
    cout << b.lmao("Bruh"); // "Bruh"
}
```
