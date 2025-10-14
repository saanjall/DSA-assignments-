// Display all the node values in a circular linked list, repeating value of head node at the
// end too. For example, if elements present in the circular linked list starting from head
// are 20 → 100 → 40 → 80 → 60, then output should be displayed as 20 100 40 80 60
// 20
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to display all nodes, repeating head value at the end
void displayCircularList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // loop until we come back to head

    cout << head->data << endl; // repeat head value at the end
}

int main() {
    // Creating nodes
    Node* n1 = new Node{20, NULL};
    Node* n2 = new Node{100, NULL};
    Node* n3 = new Node{40, NULL};
    Node* n4 = new Node{80, NULL};
    Node* n5 = new Node{60, NULL};

    // Linking nodes to form a circular linked list
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1; // makes it circular

    cout << "Circular Linked List elements: ";
    displayCircularList(n1);

    return 0;
}
