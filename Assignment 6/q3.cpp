// Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Linked List.
#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Function to find size of Doubly Linked List
int sizeOfDoublyList(DNode* head) {
    int count = 0;
    DNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Node structure for Circular Linked List
struct CNode {
    int data;
    CNode* next;
};

// Function to find size of Circular Linked List
int sizeOfCircularList(CNode* head) {
    if (head == NULL)
        return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // Doubly Linked List: 10 <-> 20 <-> 30
    DNode* d1 = new DNode{10, NULL, NULL};
    DNode* d2 = new DNode{20, d1, NULL};
    DNode* d3 = new DNode{30, d2, NULL};
    d1->next = d2;
    d2->next = d3;
    cout << "Size of Doubly Linked List: " << sizeOfDoublyList(d1) << endl;

    // Circular Linked List: 1 -> 2 -> 3 -> back to head
    CNode* c1 = new CNode{1, NULL};
    CNode* c2 = new CNode{2, NULL};
    CNode* c3 = new CNode{3, NULL};
    c1->next = c2;
    c2->next = c3;
    c3->next = c1; // make it circular
    cout << "Size of Circular Linked List: " << sizeOfCircularList(c1) << endl;

    return 0;
}
