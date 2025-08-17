#include <iostream>
#include <string>
using namespace std;

// Function to concatenate
void concatenate() {
    string str1, str2;
    cout << "Enter first string: ";
    cin.ignore();
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    cout << "Concatenated string: " << str1 + str2 << endl;
}

// Function to reverse
void reverseString() {
    string str;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, str);

    cout << "Reversed string: ";
    for (int i = str.length() - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}

// Function to delete vowels
void deleteVowels() {
    string str, result = "";
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, str);

    for (char c : str) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;
}

// Function to sort strings
void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    string arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i+1 << ": ";
        getline(cin, arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

// Function to convert uppercase to lowercase
void toLowercase() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "Not an uppercase letter!" << endl;
    }
}

// Main program
int main() {
    int choice;
    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels \n";
        cout << "4. Sort strings alphabetically\n";
        cout << "5. Convert uppercase to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: concatenate(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: toLowercase(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
