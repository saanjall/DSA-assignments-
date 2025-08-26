#include <iostream>
#include <stack>
using namespace std;
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
bool isBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);  
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty() || !isMatching(s.top(), c)) {
                return false;  // mismatch found
            }
            s.pop();
        }
    }
    return s.empty(); 
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced Expression ✅" << endl;
    else
        cout << "Unbalanced Expression ❌" << endl;

    return 0;
}
