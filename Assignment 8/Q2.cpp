#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert into BST (Iterative)
Node* insert(Node* root, int val) {
    Node* newNode = new Node(val);
    if (!root) return newNode;

    Node* parent = nullptr;
    Node* curr = root;
    while (curr) {
        parent = curr;
        if (val < curr->data)
            curr = curr->left;
        else if (val > curr->data)
            curr = curr->right;
        else
            return root; // no duplicates
    }
    if (val < parent->data) parent->left = newNode;
    else parent->right = newNode;

    return root;
}

// (a) Search iterative
bool search(Node* root, int key) {
    Node* curr = root;
    while (curr) {
        if (curr->data == key) return true;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}

// (b) Minimum element
int findMin(Node* root) {
    Node* curr = root;
    while (curr && curr->left)
        curr = curr->left;
    return curr->data;
}

// (c) Maximum element
int findMax(Node* root) {
    Node* curr = root;
    while (curr && curr->right)
        curr = curr->right;
    return curr->data;
}

// (d) Inorder Successor
Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = nullptr;
    while (root) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

// (e) Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = nullptr;
    while (root) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Search 60: " << (search(root, 60) ? "Found" : "Not Found") << endl;
    cout << "Minimum Element: " << findMin(root) << endl;
    cout << "Maximum Element: " << findMax(root) << endl;

    Node* target = root->left; // 30
    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);
    cout << "Inorder Successor of " << target->data << ": " 
         << (succ ? to_string(succ->data) : "None") << endl;
    cout << "Inorder Predecessor of " << target->data << ": " 
         << (pred ? to_string(pred->data) : "None") << endl;
}
