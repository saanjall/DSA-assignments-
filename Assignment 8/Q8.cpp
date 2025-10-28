#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Convert BST to Doubly Linked List (Inorder Iterative)
Node* bstToDLL(Node* root) {
    if (!root) return nullptr;
    stack<Node*> st;
    Node* curr = root;
    Node* head = nullptr, *prev = nullptr;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        if (!head)
            head = curr;
        curr->left = prev;
        if (prev)
            prev->right = curr;
        prev = curr;

        curr = curr->right;
    }
    return head;
}

// Merge two sorted doubly linked lists
Node* mergeDLL(Node* first, Node* second) {
    if (!first) return second;
    if (!second) return first;

    Node* head = nullptr;
    Node* tail = nullptr;

    while (first && second) {
        Node* smaller = (first->data < second->data) ? first : second;
        if (smaller == first)
            first = first->right;
        else
            second = second->right;

        if (!head) {
            head = smaller;
            tail = smaller;
            head->left = nullptr;
        } else {
            tail->right = smaller;
            smaller->left = tail;
            tail = smaller;
        }
    }
    // Attach remaining nodes
    Node* remain = first ? first : second;
    while (remain) {
        tail->right = remain;
        remain->left = tail;
        tail = remain;
        remain = remain->right;
    }

    return head;
}

// Display Doubly Linked List
void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
}

int main() {
    // BST 1
    Node* root1 = new Node(30);
    root1->left = new Node(20);
    root1->right = new Node(40);

    // BST 2
    Node* root2 = new Node(50);
    root2->left = new Node(35);
    root2->right = new Node(70);

    Node* list1 = bstToDLL(root1);
    Node* list2 = bstToDLL(root2);

    Node* merged = mergeDLL(list1, list2);
    cout << "Merged Doubly Linked List: ";
    printDLL(merged);
}
