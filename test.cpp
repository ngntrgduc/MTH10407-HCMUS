#include <iostream>
#include <string>

using namespace std;

// template <typename T>

// // class Bruh {
// // public:
// //     Bruh() {}
// //     T lmao(T lmao) {
// //         return lmao;
// //     }
// // };

// T add(T a, T b) {
//         return a + b;
// }

// int main() {
//     int a = 2, b = 4;
//     string c = "hello", d = " world";
//     cout << add(a, b);
//     cout << add(c, d);
// }

class Bruh {
    int lmao;
public:
    Bruh(int lmao) {
        lmao = lmao;
    }

    Bruh(const Bruh& bruh) {
        lmao = bruh.lmao;
    }

    void get() {
        cout << lmao << '\n';
    }
};

int main() {
    Bruh a(1);
    Bruh b(a);
    a.get();
    b.get();
}