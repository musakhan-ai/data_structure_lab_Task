
#include <iostream>
using namespace std;

class Node {
public:
    int bookID;
    Node* left;
    Node* right;

    Node(int id) {
        bookID = id;
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

    Node* insert(Node* node, int id) {
        if (node == NULL) {
            return new Node(id);
        }

        if (id < node->bookID) {
            node->left = insert(node->left, id);
        }
        else if (id > node->bookID) {
            node->right = insert(node->right, id);
        }

        return node;
    }

    void addBook(int id) {
        root = insert(root, id);
    }

    bool search(Node* node, int id, int& comparisons) {
        if (node == NULL) {
            return false;
        }

        comparisons++;

        if (node->bookID == id) {
            return true;
        }

        if (id < node->bookID) {
            return search(node->left, id, comparisons);
        }

        return search(node->right, id, comparisons);
    }

    void findBook(int id) {
        int comparisons = 0;

        if (search(root, id, comparisons)) {
            cout << "Book Found" << endl;
        }
        else {
            cout << "Book Not Found" << endl;
        }

        cout << "Number of comparisons: "
             << comparisons << endl;
    }
};

int main() {
    BST library;

    library.addBook(40);
    library.addBook(20);
    library.addBook(60);
    library.addBook(10);
    library.addBook(30);
    library.addBook(50);
    library.addBook(70);

    int id;

    cout << "Enter book ID to search: ";
    cin >> id;

    library.findBook(id);

    return 0;
}
