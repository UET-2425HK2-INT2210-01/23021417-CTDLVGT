// Min-Heap Implementation
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap; // Mảng chứa các phần tử của heap

    int parent(int i) { return (i - 1) / 2; }  // Tìm chỉ số cha
    int left(int i) { return 2 * i + 1; }      // Tìm chỉ số con trái
    int right(int i) { return 2 * i + 2; }     // Tìm chỉ số con phải

    // Hàm duy trì tính chất heap khi xóa phần tử (heapify từ trên xuống)
    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest); // Gọi đệ quy
        }
    }

    // Hàm duy trì tính chất heap khi thêm phần tử (heapify từ dưới lên)
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i); // Tiếp tục đẩy lên
        }
    }

public:
    // Chèn phần tử mới vào heap
    void insert(int value) {
        heap.push_back(value);    // Thêm phần tử vào cuối mảng
        heapifyUp(heap.size() - 1); // Duy trì tính chất heap
    }

    // Xóa phần tử khỏi heap
    void remove(int value) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) return; // Không tìm thấy phần tử cần xóa

        swap(heap[index], heap.back()); // Đưa phần tử cần xóa xuống cuối mảng
        heap.pop_back(); // Xóa phần tử

        if (index < heap.size()) {
            heapifyUp(index);   // Kiểm tra từ dưới lên
            heapifyDown(index); // Kiểm tra từ trên xuống
        }
    }

    // In ra các phần tử của heap
    void print() {
        for (int value : heap) cout << value << " ";
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};

    // Chèn các giá trị ban đầu vào heap
    for (int value : initialValues)
        heap.insert(value);

    cout << "Heap after initial insertion: ";
    heap.print();

    // Chèn thêm các giá trị
    heap.insert(14);
    heap.insert(0);
    heap.insert(35);

    cout << "After inserting 14, 0, 35: ";
    heap.print();

    // Xóa các giá trị khỏi heap
    heap.remove(6);
    heap.remove(13);
    heap.remove(35);
    heap.print();

    return 0;
}
