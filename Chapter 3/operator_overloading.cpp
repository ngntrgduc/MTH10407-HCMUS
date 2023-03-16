#include <iostream>

using namespace std;

class Array {
    int* a;
    int size;
public:
    Array& operator=(const Array& src) {
        if (this != &src) {
            delete[] a;
            size = src.size;
            a = new int[size];
            for (int i = 0; i < size; i++) {
                a[i] = src.a[i];
            }
        }
        return *this;
    }

    // void set(int src[]) {
    //     a = new int[src.size()];
    //     // for (int i = 0; i < src.size(); i++) {
    //     //     a[i] = src[i];
    //     // }
    // }
};



int main() {

}