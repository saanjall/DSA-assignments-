#include <iostream>
using namespace std;

// (a) Diagonal Matrix
void diagonalMatrix() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;

    int diag[n];
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (b) Tri-diagonal Matrix
void triDiagonalMatrix() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int lower[n-1], diag[n], upper[n-1];
    cout << "Enter main diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Enter lower diagonal elements: ";
    for (int i = 0; i < n-1; i++) cin >> lower[i];

    cout << "Enter upper diagonal elements: ";
    for (int i = 0; i < n-1; i++) cin >> upper[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else if (i == j+1) cout << lower[j] << " ";
            else if (j == i+1) cout << upper[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (c) Lower Triangular Matrix
void lowerTriangularMatrix() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int arr[size];
    cout << "Enter elements row by row:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << arr[i*(i+1)/2 + j] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (d) Upper Triangular Matrix
void upperTriangularMatrix() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int arr[size];
    cout << "Enter elements row by row:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) cout << arr[j*(j+1)/2 + i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

// (e) Symmetric Matrix
void symmetricMatrix() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int arr[size];
    cout << "Enter lower triangular elements (including diagonal):\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << arr[i*(i+1)/2 + j] << " ";
            else cout << arr[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }
}

// Main Menu
int main() {
    int choice;
    do {
  
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: diagonalMatrix(); break;
            case 2: triDiagonalMatrix(); break;
            case 3: lowerTriangularMatrix(); break;
            case 4: upperTriangularMatrix(); break;
            case 5: symmetricMatrix(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
