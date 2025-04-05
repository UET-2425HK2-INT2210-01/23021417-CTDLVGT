#include <iostream>      // Thư viện nhập xuất
#include <vector>        // Thư viện vector
#include <algorithm>     // Thư viện chứa next_permutation

using namespace std;

int main() {
    int n;
    cin >> n;                        // Nhập n từ bàn phím

    vector<int> a(n);               // Tạo vector để chứa dãy 1 đến n

    for (int i = 0; i < n; ++i)
        a[i] = i + 1;               // Gán giá trị 1 đến n cho vector

    // Duyệt tất cả các hoán vị theo thứ tự từ nhỏ đến lớn
    do {
        for (int i = 0; i < n; ++i)
            cout << a[i];          // In từng phần tử trong hoán vị
        cout << endl;              // Xuống dòng sau mỗi hoán vị
    } while (next_permutation(a.begin(), a.end())); // Sinh hoán vị kế tiếp

    return 0;
}
