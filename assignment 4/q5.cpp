#include <iostream>
#include <queue>
using namespace std;


class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        swap(q1, q2);
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Top element: " << q1.front() << endl;
        q2.push(q1.front());
        q1.pop();

        swap(q1, q2);
    }

    bool empty() {
        return q1.empty();
    }
};


class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

      
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
    }
};


int main() {
    StackTwoQueues s1;
    StackOneQueue s2;

    int choice, type, value;

    cout << "Choose Implementation:\n1. Stack using Two Queues\n2. Stack using One Queue\n";
    cin >> type;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Top\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                if (type == 1) s1.push(value);
                else s2.push(value);
                break;
            case 2:
                if (type == 1) s1.pop();
                else s2.pop();
                break;
            case 3:
                if (type == 1) s1.top();
                else s2.top();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
