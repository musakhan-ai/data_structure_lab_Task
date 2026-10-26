
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

class FamilyTree {
public:
    Node* root;

    FamilyTree() {
        root = NULL;
    }

    void display(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << "Person: " << node->name;

        cout << " | Left Child: ";
        if (node->left != NULL)
            cout << node->left->name;
        else
            cout << "None";

        cout << " | Right Child: ";
        if (node->right != NULL)
            cout << node->right->name;
        else
            cout << "None";

        cout << endl;

        display(node->left);
        display(node->right);
    }
};

int main() {
    FamilyTree tree;

    tree.root = new Node("Grandfather");

    tree.root->left = new Node("Father");
    tree.root->right = new Node("Uncle");

    tree.root->left->left = new Node("Ali");
    tree.root->left->right = new Node("Ahmed");

    tree.root->right->left = new Node("Usman");
    tree.root->right->right = new Node("Hamza");

    cout << "Family Tree Information:" << endl;
    tree.display(tree.root);

    return 0;
}
