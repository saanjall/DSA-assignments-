#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert node (Iterative)
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
    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

// Find minimum node (for delete helper)
Node* findMinNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left)
        curr = curr->left;
    return curr;
}

// Delete node (Iterative)
Node* deleteNode(Node* root, int key) {
    Node* parent = nullptr;
    Node* curr = root;
    while (curr && curr->data != key) {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (!curr) return root;

    // No child
    if (!curr->left && !curr->right) {
        if (!parent) return nullptr;
        if (parent->left == curr) parent->left = nullptr;
        else parent->right = nullptr;
        delete curr;
    }
    // One child
    else if (!curr->left || !curr->right) {
        Node* child = curr->left ? curr->left : curr->right;
        if (!parent) return child;
        if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;
        delete curr;
    }
    // Two children
    else {
        Node* succ = findMinNode(curr->right);
        int val = succ->data;
        root = deleteNode(root, succ->data);
        curr->data = val;
    }
    return root;
}

// Maximum Depth (Level Order)
int maxDepth(Node* root) {
    if (!root) return 0;
    queue<Node*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}

// Minimum Depth (Level Order)
int minDepth(Node* root) {
    if (!root) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        Node* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (!node->left && !node->right)
            return depth;
        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }
    return 0;
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

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 20);
    cout << "After deleting 20, Max Depth: " << maxDepth(root) << endl;
}
