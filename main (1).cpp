#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* node;

node makeNode(int x) {
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

void insert(node& head, int pos, int x) {
    node tmp = makeNode(x);
    if (pos == 0) {
        tmp->next = head;
        head = tmp;
        return;
    }
    node p = head;
    for (int i = 0; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) return;
    tmp->next = p->next;
    p->next = tmp;
}

void deleteNode(node& head, int pos) {
    if (head == NULL) return;
    if (pos == 0) {
        node tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    node p = head;
    for (int i = 0; i < pos - 1 && p->next != NULL; i++) {
        p = p->next;
    }
    if (p->next == NULL) return;
    node tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}

void printList(node head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "insert") {
            int p, x;
            cin >> p >> x;
            insert(head, p, x);
        } else if (op == "delete") {
            int p;
            cin >> p;
            deleteNode(head, p);
        }
    }
    printList(head);
    return 0;
}
