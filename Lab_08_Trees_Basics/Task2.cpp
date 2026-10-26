
#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    Node* left;
    Node* right;

    Node(int value) {
        roll = value;
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

        if (value < node->roll) {
            node->left = insert(node->left, value);
        }
        else if (value > node->roll) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void addRollNumber(int value) {
        root = insert(root, value);
    }

    void inOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrder(node->left);
        cout << node->roll << " ";
        inOrder(node->right);
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.addRollNumber(45);
    tree.addRollNumber(25);
    tree.addRollNumber(65);
    tree.addRollNumber(15);
    tree.addRollNumber(35);
    tree.addRollNumber(55);
    tree.addRollNumber(75);

    int roll1, roll2;

    cout << "Enter first additional roll number: ";
    cin >> roll1;

    cout << "Enter second additional roll number: ";
    cin >> roll2;

    tree.addRollNumber(roll1);
    tree.addRollNumber(roll2);

    cout << "Roll Numbers in Ascending Order: ";
    tree.display();

    return 0;
}
