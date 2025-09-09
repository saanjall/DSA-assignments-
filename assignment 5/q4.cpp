// Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;   // Save next
            curr->next = prev;   // Reverse current node
            prev = curr;         // Move prev forward
            curr = next;         // Move curr forward
        }

        head = prev; // New head
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Example input: 1->2->3->4->NULL
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
