
#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// BFS Traversal Function
void BFS(Node* root) {

    if (root == NULL) {
        return;
    }

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        Node* current = q.front();

        cout << current->data << " ";

        q.pop();

        if (current->left != NULL) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {

    // Creating nodes
    Node* root = new Node("Electronics");

    Node* n1 = new Node("Clothing");
    Node* n2 = new Node("Mobiles");
    Node* n3 = new Node("Laptops");
    Node* n4 = new Node("Men");
    Node* n5 = new Node("Women");
    Node* n6 = new Node("Accessories");

    // Connecting nodes
    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    // Displaying BFS Traversal
    cout << "Product Categories using BFS:" << endl;

    BFS(root);

    return 0;
}
