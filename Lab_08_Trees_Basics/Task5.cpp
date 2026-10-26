
#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->id) {
            node->left = insert(node->left, value);
        }
        else if (value > node->id) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void addPatient(int value) {
        root = insert(root, value);
    }
    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrder(node->left);
        cout << node->id << " ";
        inOrder(node->right);
    }
    void preOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->id << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    void postOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << node->id << " ";
    }
};

int main() {
    BST hospital;

    hospital.addPatient(40);
    hospital.addPatient(20);
    hospital.addPatient(60);
    hospital.addPatient(10);
    hospital.addPatient(30);
    hospital.addPatient(50);
    hospital.addPatient(70);

    cout << "In-order Traversal: ";
    hospital.inOrder(hospital.root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    hospital.preOrder(hospital.root);
    cout << endl;

    cout << "Post-order Traversal: ";
    hospital.postOrder(hospital.root);
    cout << endl;

    return 0;
}
