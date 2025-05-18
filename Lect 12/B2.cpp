#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc cạnh: gồm 2 đầu mút u, v và trọng số (chi phí) w
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

// Cấu trúc Disjoint Set Union (Union-Find) để kiểm tra chu trình
class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    bool unite(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) return false;
        if (rank[ru] < rank[rv])
            parent[ru] = rv;
        else if (rank[ru] > rank[rv])
            parent[rv] = ru;
        else {
            parent[rv] = ru;
            rank[ru]++;
        }
        return true;
    }
};

int main() {
    ifstream fin("connection.txt");
    ofstream fout("connection.out");

    int n, m;
    fin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        fin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<Edge> mst;
    int totalCost = 0;

    for (const Edge& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalCost += e.w;
        }
    }

    fout << totalCost << endl;
    for (const Edge& e : mst) {
        fout << e.u << " " << e.v << " " << e.w << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
