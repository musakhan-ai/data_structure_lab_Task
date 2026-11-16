
#include<iostream>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

// In-order Traversal (Left, Root, Right)
void Inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    Inorder(root->left);
    cout << root->folder << " ";
    Inorder(root->right);
}

// Pre-order Traversal (Root, Left, Right)
void Preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->folder << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Post-order Traversal (Left, Right, Root)
void Postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->folder << " ";
}

int main() {

    // Creating nodes
    Node* root = new Node("Computer");

    Node* n1 = new Node("Documents");
    Node* n2 = new Node("Pictures");
    Node* n3 = new Node("Assignments");
    Node* n4 = new Node("Projects");
    Node* n5 = new Node("Family");
    Node* n6 = new Node("Videos");

    // Connecting nodes
    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    // Displaying DFS Traversals
    cout << "In-order Traversal: ";
    Inorder(root);

    cout << "\nPre-order Traversal: ";
    Preorder(root);

    cout << "\nPost-order Traversal: ";
    Postorder(root);

    return 0;
}
