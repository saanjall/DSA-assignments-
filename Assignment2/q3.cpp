// Design the Logic to Find a Missing Number in a Sorted Array.
#include <iostream>
using namespace std;
int findMissing(int arr[ ], int n) {
int l = 0, h = n - 1;
int start = arr[0];

while (l <= h) {
int m = l + (h - l) / 2;
if (arr[m] - m != start) {
h = m - 1;
} else {
l = m + 1;
}
}
return start + l;
}

int main() {
int arr[] = {1, 2, 3, 5, 6, 7};
int n = sizeof(arr) / sizeof(arr[0]);
cout << "Missing number: " << findMissing(arr, n);
return 0;
}
