#include <iostream>
#include <vector>

using namespace std;
//hàm DFS
void DFS(int node, vector<vector<int>> &adj, vector<bool> & visited)
{
    visited[node] = true; // Đánh dấu đã thăm đỉnh này
    
    for(int neighbour : adj[node]) // Duyệt tất cả đỉnh kề của node
    {
        if(!visited[neighbour]) // Đk của if là nếu đỉnh kề chưa được thăm
        {
            DFS(neighbour, adj, visited); //Gọi đệ quy DFS tiếp tục từ đỉnh kề
        }
    }
}

int main()
{
    cout << "Nhap so dinh n va so canh m: ";
    int n, m;
        //nhập số đỉnh n và số cạnh m
    cin >> n >> m; 
        // Tạo danh sách kề từ 1 đến n
    vector<vector<int>> adj(n + 1); 
        // Nhập m cạnh
    for( int i = 0; i < m; i++)
    {
        int x, y;
        cout << "Nhap canh noi giua x va y: ";
        cin >> x >> y;          //nhập cạnh nối giữa x và y
        adj[x].push_back(y);    // Thêm y vào danh sách kề của x
        adj[y].push_back(x);    // Thêm x vào danh sách kề của y ( đồ thị 2 chiều)
    }
    
    vector<bool> visited(n + 1, false);     //Tạo mảng visited( ban đầu tất cả là false)
    int tplt = 0;   //Đếm số thành phần liên thông
        //Duyệt qua tất cả các đỉnh
    for( int i = 1; i <= n; i++)
    {
        if(!visited[i])             //Nếu đỉnh này chưa thăm
        {                           
            DFS(i, adj, visited);   //Gọi DFS từ đỉnh này
            tplt++;                 // Tăng biến đếm
        }
    }
    cout << "So thanh phan lien thong la: "<< tplt << endl;           //In kết quả
    return 0;
}