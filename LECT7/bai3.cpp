#include <iostream>  // Thư viện nhập xuất

using namespace std;

// Hàm đệ quy tính ước chung lớn nhất (GCD) của 2 số a và b
int gcd(int a, int b) {
    if (b == 0)           // Trường hợp cơ sở: nếu b = 0 thì GCD là a
        return a;
    return gcd(b, a % b); // Gọi đệ quy: GCD(a, b) = GCD(b, a % b)
}

int main() {
    int x, y;
    cin >> x >> y;           // Nhập 2 số nguyên từ bàn phím
    cout << gcd(x, y) << endl; // In ra ước chung lớn nhất
    return 0;
}
