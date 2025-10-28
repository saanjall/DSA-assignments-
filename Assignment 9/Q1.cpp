#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int> &arr, int n, int i, bool increasing) {
    int extreme = i; // largest (for max-heap) or smallest (for min-heap)
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (increasing) {
        // For increasing order → max-heap
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else {
        // For decreasing order → min-heap
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

// Heapsort Function
void heapSort(vector<int> &arr, bool increasing = true) {
    int n = arr.size();

    // Build heap (max or min depending on order)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    vector<int> arr = {45, 20, 35, 15, 10, 50};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Increasing Order
    heapSort(arr, true);
    cout << "Sorted in Increasing Order: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Decreasing Order
    vector<int> arr2 = {45, 20, 35, 15, 10, 50};
    heapSort(arr2, false);
    cout << "Sorted in Decreasing Order: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
