#include <iostream>  // Thư viện nhập xuất

using namespace std;

// Hàm đệ quy sinh chuỗi nhị phân độ dài n
void generate(int n, string s = "") {
    if (s.length() == n) {       // Khi chuỗi đạt độ dài n
        cout << s << endl;       // In ra chuỗi
        return;
    }

    generate(n, s + "0");        // Thêm '0' vào chuỗi và gọi đệ quy tiếp
    generate(n, s + "1");        // Thêm '1' vào chuỗi và gọi đệ quy tiếp
}

int main() {
    int n;
    cin >> n;                    // Nhập số nguyên n từ bàn phím
    generate(n);                 // Gọi hàm sinh chuỗi nhị phân
    return 0;
}
