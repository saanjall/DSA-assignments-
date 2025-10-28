#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);
    pq.insert(40);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();

    cout << "Highest Priority Element: " << pq.getMax() << endl;

    cout << "Deleting Highest Priority Element..." << endl;
    pq.deleteMax();

    cout << "Priority Queue after deletion: ";
    pq.display();

    return 0;
}
