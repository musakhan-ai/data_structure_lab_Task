
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

    void addEmployee(int value) {
        root = insert(root, value);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL) {
            return NULL;
        }

        if (value < node->id) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->id) {
            node->right = deleteNode(node->right, value);
        }
        else {
            if (node->left == NULL &&
                node->right == NULL) {
                delete node;
                return NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->id = temp->id;
            node->right = deleteNode(node->right, temp->id);
        }

        return node;
    }

    void removeEmployee(int value) {
        root = deleteNode(root, value);
    }

    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrder(node->left);
        cout << node->id << " ";
        inOrder(node->right);
    }

    void display() {
        cout << "Remaining Employee IDs: ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.addEmployee(50);
    tree.addEmployee(30);
    tree.addEmployee(70);
    tree.addEmployee(20);
    tree.addEmployee(40);
    tree.addEmployee(60);
    tree.addEmployee(80);

    cout << "Original Employee IDs: ";
    tree.display();

    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    tree.removeEmployee(id);

    tree.display();

    return 0;
}
