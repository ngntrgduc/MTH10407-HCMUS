// #include <iostream>

// using namespace std;

// class Object {
// public:
//     virtual ~Object() = 0;
// };

// class Container {
//     int count;
// public:
//     virtual void put(Object&) = 0;
//     virtual Object& get() = 0;
//     virtual Object& peek() = 0;
//     virtual bool isEmpty() const { return count == 0; }
//     virtual bool isFull() const { return count == 100; }
//     virtual int numOfElements() const { return count; }
// };

// class Stack : public Container {
//     stvector<Object> listObjects;
// public:
//     void push(Object& obj) {
//         if (!isFull()) {
//             listObjects.push_back(obj);
//             count++;
//         }
//     }
//     Object& pop() {
//         if (!isEmpty()) {
//             count--;
//             return listObjects.pop();
//         }
//     }
//     Object& top() {
//         if (!isEmpty()) return listObjects[0];
//     }
// };

// int main() {
//     Object a;

// }