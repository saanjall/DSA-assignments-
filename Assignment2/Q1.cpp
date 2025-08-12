//Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of Ο(log n) in comparison to the Linear Search.
#include <iostream>
using namespace std;
int binarySearch(int arr[ ], int size, int val) {
int l = 0;
int h = size - 1;

while (l <= h) {
int m = l + (h - l) / 2;

if (arr[m] == val) {
return m;
}
else if (arr[m] < val) {
l = m + 1;
}
else {
h = m - 1;
}
}

return -1;
}

int main() {
int arr[ ] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
int size = sizeof(arr) / sizeof(arr[0]);
int val;
cin >> val;
int result = binarySearch(arr, size, val);
if (result != -1) {
cout << "Element found at index " << result << endl;
} else {
cout << "Element not found in array." << endl;
}
return 0;
}
