#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// Construct Binary Tree from Preorder and Inorder (Iterative)
Node* buildTree(int preorder[], int inorder[], int n) {
    if (n == 0) return nullptr;

    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++)
        inMap[inorder[i]] = i;

    Node* root = new Node(preorder[0]);
    stack<Node*> st;
    st.push(root);

    for (int i = 1; i < n; i++) {
        Node* temp = nullptr;
        while (!st.empty() && inMap[preorder[i]] > inMap[st.top()->data]) {
            temp = st.top();
            st.pop();
        }
        if (temp)
            temp->right = new Node(preorder[i]);
        else
            st.top()->left = new Node(preorder[i]);
        st.push(temp ? temp->right : st.top()->left);
    }

    return root;
}

// Inorder traversal check
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int inorder[]  = {1, 5, 7, 10, 40, 50};
    int n = 6;

    Node* root = buildTree(preorder, inorder, n);

    cout << "Inorder of Constructed Tree: ";
    inorder(root);
}
