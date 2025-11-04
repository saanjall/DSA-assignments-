#include <iostream>
#include <vector>
using namespace std;

// -------------------------------
// Improved (Bidirectional) Selection Sort
// -------------------------------
void improvedSelectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n / 2; i++) {
        int minIndex = i;
        int maxIndex = i;

        // Find the min and max in the unsorted part
        for (int j = i; j < n - i; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        // Move the minimum element to the front
        swap(arr[i], arr[minIndex]);

        // ⚠️ If we just swapped the maximum element to 'minIndex',
        // we need to correct maxIndex because it points to the wrong location now
        if (maxIndex == i)
            maxIndex = minIndex;

        // Move the maximum element to the end
        swap(arr[n - i - 1], arr[maxIndex]);
    }
}

// -------------------------------
// Utility Function
// -------------------------------
void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// -------------------------------
// Main Function
// -------------------------------
int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 90, 45};

    cout << "Original Array: ";
    printArray(arr);

    improvedSelectionSort(arr);

    cout << "Sorted Array (Improved Selection Sort): ";
    printArray(arr);

    return 0;
}
