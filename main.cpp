#include <iostream>
using namespace std;

// Node class representing a node in the binary search tree
class Node {
public:
    int key;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

// Utility function to insert a new node with a given key into the BST
Node* insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    return root;
}

// In-order traversal: Left, Root, Right
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Function to clone a BST
Node* cloneBST(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Create a new node with the same key as the root
    Node* clonedNode = new Node(root->key);
    
    // Recursively clone the left and right subtrees
    clonedNode->left = cloneBST(root->left);
    clonedNode->right = cloneBST(root->right);

    return clonedNode;
}

// Main function to demonstrate BST insertion, traversal, and cloning
int main() {
    Node* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "In-order traversal of the original tree: ";
    inorderTraversal(root);
    cout << endl;

    // Clone the BST
    Node* clonedRoot = cloneBST(root);

    cout << "In-order traversal of the cloned tree: ";
    inorderTraversal(clonedRoot);
    cout << endl;

    return 0;
}
