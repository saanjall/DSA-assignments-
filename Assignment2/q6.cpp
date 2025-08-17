#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

// Function to input sparse matrix in triplet form
void inputSparse(Triplet mat[], int &n, int &rows, int &cols) {
    cout << "Enter rows and cols of matrix: ";
    cin >> rows >> cols;
    cout << "Enter number of non-zero elements: ";
    cin >> n;

    mat[0].row = rows;
    mat[0].col = cols;
    mat[0].val = n;

    cout << "Enter (row col value) for each non-zero element:\n";
    for (int i = 1; i <= n; i++) {
        cin >> mat[i].row >> mat[i].col >> mat[i].val;
    }
}

// (a) Transpose
void transpose(Triplet mat[], Triplet result[]) {
    int rows = mat[0].row, cols = mat[0].col, n = mat[0].val;

    result[0].row = cols;
    result[0].col = rows;
    result[0].val = n;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[j].col == i) {
                result[k].row = mat[j].col;
                result[k].col = mat[j].row;
                result[k].val = mat[j].val;
                k++;
            }
        }
    }
}

// (b) Addition
void add(Triplet A[], Triplet B[], Triplet C[]) {
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        cout << "Addition not possible (different dimensions).\n";
        return;
    }

    C[0].row = A[0].row;
    C[0].col = A[0].col;

    int i = 1, j = 1, k = 1;
    while (i <= A[0].val && j <= B[0].val) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        } else {
            C[k] = A[i];
            C[k].val = A[i].val + B[j].val;
            k++; i++; j++;
        }
    }
    while (i <= A[0].val) C[k++] = A[i++];
    while (j <= B[0].val) C[k++] = B[j++];

    C[0].val = k - 1;
}

// (c) Multiplication
void multiply(Triplet A[], Triplet B[], Triplet C[]) {
    if (A[0].col != B[0].row) {
        cout << "Multiplication not possible (dimension mismatch).\n";
        return;
    }

    int r1 = A[0].row, c1 = A[0].col, r2 = B[0].row, c2 = B[0].col;
    int result[r1][c2] = {0};

    for (int i = 1; i <= A[0].val; i++) {
        for (int j = 1; j <= B[0].val; j++) {
            if (A[i].col == B[j].row) {
                result[A[i].row][B[j].col] += A[i].val * B[j].val;
            }
        }
    }

    // Convert to triplet
    int k = 1;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            if (result[i][j] != 0) {
                C[k].row = i;
                C[k].col = j;
                C[k].val = result[i][j];
                k++;
            }
        }
    }
    C[0].row = r1;
    C[0].col = c2;
    C[0].val = k - 1;
}

// Function to print triplet form
void printTriplet(Triplet mat[]) {
    int n = mat[0].val;
    cout << "\nRow Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << endl;
    }
}

int main() {
    Triplet A[50], B[50], C[100];
    int choice, nA, nB, rows, cols;

    do {
        cout << "\n--- Sparse Matrix Menu ---\n";
        cout << "1. Transpose\n";
        cout << "2. Addition\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            inputSparse(A, nA, rows, cols);
            transpose(A, C);
            cout << "Original Matrix in Triplet:\n"; printTriplet(A);
            cout << "Transpose Matrix in Triplet:\n"; printTriplet(C);
        }
        else if (choice == 2) {
            cout << "Enter Matrix A:\n";
            inputSparse(A, nA, rows, cols);
            cout << "Enter Matrix B:\n";
            inputSparse(B, nB, rows, cols);
            add(A, B, C);
            cout << "Result of Addition in Triplet:\n"; printTriplet(C);
        }
        else if (choice == 3) {
            cout << "Enter Matrix A:\n";
            inputSparse(A, nA, rows, cols);
            cout << "Enter Matrix B:\n";
            inputSparse(B, nB, rows, cols);
            multiply(A, B, C);
            cout << "Result of Multiplication in Triplet:\n"; printTriplet(C);
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
