#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    vector<int> tree[1001]; // Danh sách kề của cây
    int parent[1001];       // Mảng lưu cha của từng nút
    int n;                  // Số lượng nút

    // Hàm khởi tạo cây
    Tree(int nodes) {
        n = nodes;
        for (int i = 1; i <= n; i++) parent[i] = -1; // Ban đầu tất cả các nút đều không có cha
    }

    // Hàm thêm cạnh vào cây
    void addEdge(int u, int v) {
        tree[u].push_back(v); // Thêm v vào danh sách con của u
        parent[v] = u;        // Gán u là cha của v
    }

    // Hàm tìm gốc của cây
    int findRoot() {
        for (int i = 1; i <= n; i++) {
            if (parent[i] == -1) return i; // Nút không có cha chính là gốc
        }
        return -1; // Không tìm thấy gốc (trường hợp lỗi)
    }

    // Hàm tính chiều cao của cây (độ sâu lớn nhất)
    int height(int root) {
        if (tree[root].empty()) return 1; // Nếu là lá thì chiều cao là 1
        int maxH = 0;
        for (int child : tree[root]) {
            maxH = max(maxH, height(child)); // Tìm chiều cao lớn nhất từ các con
        }
        return maxH + 1; // Chiều cao của cây là max chiều cao của con + 1
    }

    // Hàm duyệt cây theo thứ tự tiên tự (Preorder)
    void preorder(int root, vector<int> &result) {
        result.push_back(root); // Thăm nút gốc trước
        for (int child : tree[root]) {
            preorder(child, result); // Duyệt cây con theo Preorder
        }
    }

    // Hàm duyệt cây theo thứ tự hậu tự (Postorder)
    void postorder(int root, vector<int> &result) {
        for (int child : tree[root]) {
            postorder(child, result); // Duyệt cây con theo Postorder
        }
        result.push_back(root); // Thăm nút gốc sau cùng
    }

    // Hàm kiểm tra cây có phải là cây nhị phân hay không
    bool isBinaryTree() {
        for (int i = 1; i <= n; i++) {
            if (tree[i].size() > 2) return false; // Nếu một nút có nhiều hơn 2 con, không phải cây nhị phân
        }
        return true;
    }

    // Hàm duyệt cây theo thứ tự trung tự (Inorder), chỉ thực hiện nếu là cây nhị phân
    void inorder(int root, vector<int> &result) {
        if (tree[root].empty()) {
            result.push_back(root); // Nếu là lá, chỉ cần thêm vào kết quả
            return;
        }
        if (!tree[root].empty()) inorder(tree[root][0], result); // Duyệt con trái trước
        result.push_back(root); // Thăm nút gốc
        if (tree[root].size() > 1) inorder(tree[root][1], result); // Duyệt con phải nếu có
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Nhập số lượng nút và cạnh
    Tree tree(n);

    // Nhập danh sách cạnh của cây
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Nhập cạnh u -> v
        tree.addEdge(u, v);
    }

    int root = tree.findRoot(); // Xác định gốc của cây

    // In ra chiều cao của cây
    cout << tree.height(root) << endl;

    // In ra thứ tự duyệt trước (Preorder)
    vector<int> pre;
    tree.preorder(root, pre);
    for (int val : pre) cout << val << " ";
    cout << endl;

    // In ra thứ tự duyệt sau (Postorder)
    vector<int> post;
    tree.postorder(root, post);
    for (int val : post) cout << val << " ";
    cout << endl;

    // Kiểm tra cây có phải cây nhị phân hay không
    if (tree.isBinaryTree()) {
        // Nếu là cây nhị phân, in thứ tự duyệt giữa (Inorder)
        vector<int> in;
        tree.inorder(root, in);
        for (int val : in) cout << val << " ";
        cout << endl;
    } else {
        // Nếu không phải cây nhị phân, in thông báo
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}
