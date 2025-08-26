#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX], front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == MAX - 1);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot enqueue " << x << endl;
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
        cout << x << " enqueued into queue." << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Nothing to dequeue." << endl;
    } else {
        cout << queue[front++] << " dequeued from queue." << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << queue[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is not Empty." << endl;
            break;
        case 5:
            if (isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is not Full." << endl;
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
