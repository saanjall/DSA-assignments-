#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Function to check if doubly linked list is palindrome
bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* left = head;
    Node* right = head;

    // Move right to end
    while (right->next != NULL)
        right = right->next;

    // Compare from both ends
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    // Example: a <-> b <-> b <-> a
    Node* n1 = new Node{'a', NULL, NULL};
    Node* n2 = new Node{'b', NULL, n1};
    Node* n3 = new Node{'b', NULL, n2};
    Node* n4 = new Node{'a', NULL, n3};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    if (isPalindrome(n1))
        cout << "The Doubly Linked List is a Palindrome.\n";
    else
        cout << "The Doubly Linked List is NOT a Palindrome.\n";

    return 0;
}