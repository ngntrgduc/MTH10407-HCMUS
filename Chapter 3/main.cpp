#include <iostream>

using namespace std;

class PhanSo {
    int tu, mau;
public:
    // PhanSo(const PhanSo& ps) { // Nếu kiểu dữ liệu không phải là con trỏ thì không cần
    //     tu = ps.tu;
    //     mau = ps.mau;
    // }

    // Constructor
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int t) {
        tu = 1;
        mau = 1;
    }

    PhanSo(int t, int m) {
        if (m < 0) {
            t = -t; m = -m;
        }
        if (m == 0) m = 1;
        tu = t;
        mau = m;
    }
    
    void get() {
        cout << tu << '/' << mau << '\n';
    }

    void update() {
        tu += 1;
        mau += 1;
    }

    // Destructor
    ~PhanSo();
};

int main() {
    PhanSo a; a.get();
    PhanSo b(5); b.get();
    PhanSo c(5, 3); c.get();

    // Phương thức tạo lập sao chép
    PhanSo d(a); d.get(); 
}