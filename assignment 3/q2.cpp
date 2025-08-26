#include <iostream>
#include <stack>   // stack library
using namespace std;

int main() {
    string str, rev = "";
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    // Push all characters of the string into stack
    for (char c : str) {
        s.push(c);
    }

    // Pop characters from stack and build reversed string
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }

    cout << "Reversed string: " << rev << endl;

    return 0;
}
