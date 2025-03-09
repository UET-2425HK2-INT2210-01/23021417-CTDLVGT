#include <iostream>
using namespace std;

struct Node {
    int value;
    int priority;
    Node* next;
    Node* prev;

    Node(int val, int pri) : value(val), priority(pri), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);

        if (!head || p > head->priority) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority >= p) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void printQueue() {
        Node* temp = head;
        cout << "(";
        while (temp) {
            cout << temp->value << ", " << temp->priority;
            if (temp->next) cout << "; ";
            temp = temp->next;
        }
        cout << ")" << endl;
    }
};

int main() {
    PriorityQueue pq;
    int n;
    cin >> n;

    while (n--) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        }
        else if (command == "dequeue") {
            pq.dequeue();
        }
    }

    pq.printQueue();
    return 0;
}
