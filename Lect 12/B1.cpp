#include <iostream>      // Thư viện nhập xuất chuẩn
#include <fstream>       // Thư viện xử lý file
#include <vector>        // Dùng vector để lưu danh sách kề
#include <queue>         // Dùng queue cho thuật toán Kahn
using namespace std;

int main() {
    ifstream fin("jobs.txt");   // Mở file input
    ofstream fout("jobs.out");  // Mở file output

    int n, m;
    fin >> n >> m;              // Đọc số công việc và số yêu cầu

    vector<vector<int>> adj(n + 1);  // Danh sách kề, chỉ số từ 1 đến n
    vector<int> in_degree(n + 1, 0); // Mảng lưu bậc vào của từng đỉnh

    // Đọc các cạnh u -> v (u phải làm trước v)
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);    // Thêm v vào danh sách kề của u
        in_degree[v]++;         // Tăng bậc vào của v
    }

    queue<int> q;

    // Bắt đầu với các đỉnh có bậc vào bằng 0 (không phụ thuộc)
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    vector<int> result; // Lưu thứ tự công việc

    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u);  // Thêm công việc vào kết quả

        for (int v : adj[u]) {
            in_degree[v]--;     // Giảm bậc vào của các đỉnh kề
            if (in_degree[v] == 0)
                q.push(v);      // Nếu v không còn phụ thuộc, thêm vào hàng đợi
        }
    }

    // Kiểm tra có đủ n công việc không (đảm bảo không có chu trình)
    if (result.size() != n) {
        fout << "Cannot sort: cycle detected\n";
    } else {
        for (int job : result)
            fout << job << " ";
        fout << endl;
    }

    return 0;
}
