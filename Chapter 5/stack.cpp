#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> data;
public:
    bool isEmpty() const { return data.size() <= 0; }

    void push(int element) {
        data.push_back(element);
    }
    
    int pop() {
        if (!isEmpty()) {
            int top = data.back();
            data.pop_back();
            return top;
        }
    }

    int top() {
        if (!isEmpty()) 
            return data.back();
    }
    
    void printStack() {
        cout << "Stack: ";
        for (int i = 0; i < data.size(); i++) { cout << data[i] << ' '; }
        cout << '\n';
    }
};

int main() {
    Stack s;
    s.push(2); s.push(3); s.push(4); s.printStack();
    s.pop(); s.printStack();
    s.push(5); s.printStack();
    cout << "Top: " << s.top() << "\n";
    s.pop(); s.printStack();
    s.pop(); s.printStack();
    cout << "Top: " << s.top() << "\n";
    s.pop(); s.printStack();
}