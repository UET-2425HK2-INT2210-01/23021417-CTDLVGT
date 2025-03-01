#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
};

int count_triplets(DoublyLinkedList& dll) {
    int count = 0;
    Node* it = dll.head;
    if (!it || !it->next || !it->next->next) return 0;
    
    it = it->next; 
    while (it->next) {
        if (it->prev->data + it->data + it->next->data == 0) {
            count++;
        }
        it = it->next;
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    DoublyLinkedList dll;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dll.append(num);
    }
    
    cout << count_triplets(dll) << endl;
    return 0;
}
