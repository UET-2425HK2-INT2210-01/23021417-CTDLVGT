// Binary Search Tree Implementation
#include <iostream>
using namespace std;

// Struct định nghĩa một node của cây BST
struct Node {
    int value;                  // Giá trị của node
    Node* left;                 // Con trái
    Node* right;                // Con phải

    Node(int v) : value(v), left(nullptr), right(nullptr) {} // Constructor khởi tạo node
};

// Lớp đại diện cho cây BST
class BST {
private:
    Node* root; // Gốc của cây

    // Hàm đệ quy để chèn một phần tử vào cây
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value); // Nếu node rỗng, tạo node mới
        if (value < node->value)
            node->left = insert(node->left, value); // Chèn vào nhánh trái nếu giá trị nhỏ hơn
        else if (value > node->value)
            node->right = insert(node->right, value); // Chèn vào nhánh phải nếu giá trị lớn hơn
        return node;
    }

    // Hàm tìm node nhỏ nhất trong cây (dùng để xóa)
    Node* findMin(Node* node) {
        while (node && node->left) node = node->left; // Đi đến node trái nhất
        return node;
    }

    // Hàm đệ quy để xóa một phần tử khỏi cây
    Node* remove(Node* node, int value) {
        if (!node) return nullptr;

        if (value < node->value)
            node->left = remove(node->left, value); // Tìm ở nhánh trái
        else if (value > node->value)
            node->right = remove(node->right, value); // Tìm ở nhánh phải
        else {
            // Node cần xóa được tìm thấy
            if (!node->left) {
                Node* temp = node->right; // Nếu không có con trái
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left; // Nếu không có con phải
                delete node;
                return temp;
            }

            // Node có hai con: Thay thế bởi giá trị nhỏ nhất bên phải
            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    // Duyệt cây theo thứ tự In-Order (LNR) và in ra giá trị
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {} // Khởi tạo cây rỗng

    void insert(int value) {
        root = insert(root, value); // Gọi hàm đệ quy chèn
    }

    void remove(int value) {
        root = remove(root, value); // Gọi hàm đệ quy xóa
    }

    void printInOrder() {
        inorder(root); // In cây theo thứ tự LNR
        cout << endl;
    }
};

int main() {
    BST tree;
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};

    // Chèn các giá trị ban đầu
    for (int value : initialValues)
        tree.insert(value);

    cout << "Binary Search Tree (In-Order): ";
    tree.printInOrder();

    // Chèn thêm các giá trị mới
    tree.insert(14);
    tree.insert(0);
    tree.insert(35);

    cout << "After inserting 14, 0, 35: ";
    tree.printInOrder();

    // Xóa các giá trị
    tree.remove(6);
    tree.remove(13);
    tree.remove(35);
    tree.printInOrder();

    return 0;
}
