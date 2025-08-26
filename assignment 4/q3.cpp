#include <iostream>
#include <queue>
using namespace std;

void mixQueue(queue<int>& q) {
    int total = q.size();

    if (total % 2 != 0) {
        cout << "Queue must have even number of elements!" << endl;
        return;
    }

    queue<int> temp;
    int mid = total / 2;

    // move first half into temp
    for (int i = 0; i < mid; i++) {
        temp.push(q.front());
        q.pop();
    }

    // now alternate elements from temp and q
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int count, item;

    cout << "Enter total elements (even only): ";
    cin >> count;

    cout << "Enter queue elements: ";
    for (int i = 0; i < count; i++) {
        cin >> item;
        q.push(item);
    }

    mixQueue(q);

    cout << "Result after interleaving: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
