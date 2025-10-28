#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Helper to build tree
Node* buildTreeHelper(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    int inIndex = inMap[rootVal];

    // Build right subtree first because postorder is processed backwards
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex, inMap);
    root->left  = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex, inMap);

    return root;
}

Node* buildTree(int inorder[], int postorder[], int n) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
        inMap[inorder[i]] = i;
    int postIndex = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex, inMap);
}

// Inorder traversal
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[]   = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int n = 6;

    Node* root = buildTree(inorder, postorder, n);
    cout << "Inorder of Constructed Tree: ";
    inorderTraversal(root);
}
