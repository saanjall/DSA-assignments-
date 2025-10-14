#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to check if linked list is circular
bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    // Create Circular Linked List: 10 -> 20 -> 30 -> back to head
    Node* c1 = new Node{10, NULL};
    Node* c2 = new Node{20, NULL};
    Node* c3 = new Node{30, NULL};
    c1->next = c2;
    c2->next = c3;
    c3->next = c1; // circular

    if (isCircular(c1))
        cout << "The Linked List is Circular.\n";
    else
        cout << "The Linked List is NOT Circular.\n";

    return 0;
}