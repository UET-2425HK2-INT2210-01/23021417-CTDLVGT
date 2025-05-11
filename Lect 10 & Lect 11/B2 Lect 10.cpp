#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Hàm tìm số cạnh ngắn nhất từ X đến Y;
int shortestPath( int n, int X, int Y, const vector<vector<int>> &adj)
{
    vector<int> distance( n + 1, -1); //Lưu khoảng cách ngắn nhất từ X đến mỗi điểm
    queue<int> q;
    
    distance[X] = 0;    //Khoảng cách từ X đến chính nó bằng 0
    q.push(X);          //Bắt đầu BFS từ X
    
    while(!q.empty())
    {
        int current = q.front();    //Lấy phần từ đầu của hàng đợi
        q.pop();                    //Xóa nó khỏi hàng đợi
        
        //Duyệt tất cả các đỉnh kề của current
        for( int neighbour : adj[current])
        {
            if(distance[neighbour] == -1) //Nếu chưa thăm
            {
                distance[neighbour] = distance[current] + 1;
                q.push(neighbour);
            }
        }
    }
    return distance[Y];     //trả về số bước đi từ X đến Y
}

int main()
{
    cout << "Nhap so dinh, canh, 2 diem can tim duong: ";
    int n, m ,X ,Y;
    cin >> n >> m >> X >> Y;
    
    vector<vector<int>> adj(n + 1);
    
    for(int i = 0; i < m; i++) //Nhập cạnh có hướng
    {
        int u, v;
        cout << "Nhap canh: ";
        cin >> u >> v;          //Nhập cạnh từ u đến v
        adj[u].push_back(v);    //Lưu vào danh sách kề
    }
    int result = shortestPath(n, X, Y, adj);    //Gọi hàm
    cout <<"Duong di ngan nhat la: "<< result << endl;
    
    return 0;
}