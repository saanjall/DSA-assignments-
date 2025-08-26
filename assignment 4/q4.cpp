#include <iostream>
#include <queue>
using namespace std;

void showFirstUnique(string s) {
    queue<char> q;
    int count[26] = {0};

    for (char ch : s) {
        count[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string text;
    cout << "Enter a string (only lowercase letters): ";
    cin >> text;

    cout << "First non-repeating sequence: ";
    showFirstUnique(text);

    return 0;
}
