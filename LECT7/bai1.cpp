#include <iostream>      // Thư viện xử lý nhập xuất chuẩn
#include <fstream>       // Thư viện để làm việc với file
#include <vector>        // Thư viện vector (danh sách động)
#include <algorithm>     // Thư viện chứa hàm sort

using namespace std;     // Giúp bỏ qua tiền tố std:: khi dùng các hàm/thành phần chuẩn

int main() {
    ifstream fin("numbers.txt");     // Mở file đầu vào để đọc dữ liệu
    ofstream fout("numbers.sorted"); // Mở file đầu ra để ghi kết quả đã sắp xếp

    vector<double> numbers; // Tạo một vector để lưu các số thực đọc được
    double x;               // Biến tạm để lưu từng số khi đọc

    // Vòng lặp đọc từng số từ file cho đến hết
    while (fin >> x) {
        numbers.push_back(x); // Thêm số vào cuối vector
    }

    // Sắp xếp vector theo thứ tự tăng dần
    sort(numbers.begin(), numbers.end());

    // Ghi các số đã sắp xếp vào file đầu ra
    for (double num : numbers) {
        fout << num << " "; // Ghi từng số ra file, cách nhau bằng dấu cách
    }

    return 0; // Kết thúc chương trình
}
