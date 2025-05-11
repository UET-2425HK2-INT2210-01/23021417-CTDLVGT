#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = 1e9;

// Phần a: Bellman-Ford tìm đường đi ngắn nhất từ s đến e
bool bellmanFord(int n, int m, int s, int e,
                 const vector<tuple<int, int, int>>& edges,
                 vector<int>& dist, vector<int>& path) {
    dist.assign(n + 1, INF);      // Đặt khoảng cách ban đầu là vô cùng
    vector<int> parent(n + 1, -1); // Mảng truy vết đường đi
    dist[s] = 0;

    // Lặp n - 1 lần cập nhật khoảng cách
    for (int i = 1; i <= n - 1; ++i) {
        for (auto [u, v, d] : edges) {
            if (dist[u] != INF && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                parent[v] = u;
            }
        }
    }

    // Truy vết đường đi ngược lại từ e về s
    int current = e;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    return dist[e] != INF;
}

// Phần b: Floyd-Warshall tính khoảng cách giữa mọi cặp
void floydWarshall(int n, const vector<vector<int>>& adjMatrix,
                   vector<vector<int>>& distMatrix) {
    distMatrix = adjMatrix;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (distMatrix[i][k] < INF && distMatrix[k][j] < INF)
                    distMatrix[i][j] = min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
}

int main() {
    ifstream inFile("dirty.txt");
    ofstream outFile("dirty.out");

    int n, m, s, e;
    inFile >> n >> m >> s >> e;

    vector<tuple<int, int, int>> edges;             // Danh sách cạnh (u, v, d)
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF)); // Ma trận kề

    // Nhập m cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        inFile >> u >> v >> d;
        edges.push_back({u, v, d});
        adj[u][v] = d;
    }

    for (int i = 1; i <= n; ++i)
        adj[i][i] = 0; // Đỉnh đến chính nó = 0

    // Phần a: Bellman-Ford từ s đến e
    vector<int> dist, path;
    bool hasPath = bellmanFord(n, m, s, e, edges, dist, path);

    if (hasPath) {
        outFile << dist[e] << "\n";
        for (int i = 0; i < path.size(); ++i)
            outFile << path[i] << (i + 1 < path.size() ? " " : "\n");
    } else {
        outFile << "INF\n";
        outFile << "No path\n";
    }

    // Phần b: Floyd-Warshall
    vector<vector<int>> allPairs;
    floydWarshall(n, adj, allPairs);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (allPairs[i][j] == INF)
                outFile << "INF";
            else
                outFile << allPairs[i][j];
            outFile << (j < n ? " " : "\n");
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}
