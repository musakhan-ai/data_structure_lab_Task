
#include<iostream>
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

int main() {

    // Creating nodes
    Node* root = new Node("HOD");

    Node* n1 = new Node("Coordinator CS");
    Node* n2 = new Node("Coordinator AI");
    Node* n3 = new Node("Faculty Member 1");
    Node* n4 = new Node("Faculty Member 2");
    Node* n5 = new Node("Faculty Member 3");
    Node* n6 = new Node("Faculty Member 4");

    // Connecting parent and child nodes
    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    // Displaying the tree
    cout << "University Department Hierarchy" << endl;

    cout << "Member: " << root->name << endl;
    cout << "Left Child: " << root->left->name << endl;
    cout << "Right Child: " << root->right->name << endl;

    cout << "\nMember: " << n1->name << endl;
    cout << "Left Child: " << n1->left->name << endl;
    cout << "Right Child: " << n1->right->name << endl;

    cout << "\nMember: " << n2->name << endl;
    cout << "Left Child: " << n2->left->name << endl;
    cout << "Right Child: " << n2->right->name << endl;

    cout << "\nMember: " << n3->name << endl;
    cout << "Left Child: NULL" << endl;
    cout << "Right Child: NULL" << endl;

    cout << "\nMember: " << n4->name << endl;
    cout << "Left Child: NULL" << endl;
    cout << "Right Child: NULL" << endl;

    cout << "\nMember: " << n5->name << endl;
    cout << "Left Child: NULL" << endl;
    cout << "Right Child: NULL" << endl;

    cout << "\nMember: " << n6->name << endl;
    cout << "Left Child: NULL" << endl;
    cout << "Right Child: NULL" << endl;

    return 0;
}
