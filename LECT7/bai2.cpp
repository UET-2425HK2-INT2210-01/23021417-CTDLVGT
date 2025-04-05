#include <iostream>      // Thư viện nhập xuất
#include <fstream>       // Thư viện làm việc với file
#include <vector>        // Thư viện vector
#include <climits>       // Thư viện để dùng hằng số INT_MIN

using namespace std;

int main() {
    ifstream fin("matrix.txt");     // Mở file đầu vào chứa ma trận
    ofstream fout("matrix.out");    // Mở file đầu ra ghi kết quả

    int m, n;                       // m: số hàng, n: số cột
    fin >> m >> n;                 // Đọc m và n từ file

    // Tạo ma trận A có m hàng và n cột
    vector<vector<int>> A(m, vector<int>(n));

    // Đọc dữ liệu ma trận từ file
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> A[i][j];

    int maxSum = INT_MIN;           // Khởi tạo tổng lớn nhất là âm vô cùng
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0; // Các tọa độ của hình chữ nhật có tổng lớn nhất

    // Duyệt tất cả các cặp hàng trên và dưới
    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0); // Mảng tạm để lưu tổng các cột từ dòng top đến bottom

        for (int bottom = top; bottom < m; ++bottom) {
            // Cộng dồn từng cột từ dòng top đến dòng bottom
            for (int i = 0; i < n; ++i)
                temp[i] += A[bottom][i];

            // Áp dụng thuật toán Kadane để tìm đoạn con có tổng lớn nhất trong temp
            int sum = 0, start = 0;
            for (int i = 0; i < n; ++i) {
                if (sum <= 0) {
                    sum = temp[i];   // Bắt đầu đoạn mới
                    start = i;       // Ghi lại vị trí bắt đầu
                } else {
                    sum += temp[i];  // Mở rộng đoạn hiện tại
                }

                // Cập nhật kết quả nếu tổng mới lớn hơn
                if (sum > maxSum) {
                    maxSum = sum;
                    r1 = top + 1;     // +1 vì đề bài đánh số từ 1
                    c1 = start + 1;
                    r2 = bottom + 1;
                    c2 = i + 1;
                }
            }
        }
    }

    // Ghi kết quả ra file: (r1, c1) đến (r2, c2) với tổng là maxSum
    fout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << "\n";
    return 0;
}
