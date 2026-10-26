
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
private:
    Node* root;

    Node* insert(Node* node, int value, bool& inserted) {
        if (node == NULL) {
            inserted = true;
            return new Node(value);
        }

        if (value < node->id) {
            node->left = insert(node->left, value, inserted);
        }
        else if (value > node->id) {
            node->right = insert(node->right, value, inserted);
        }

        return node;
    }
    bool search(Node* node, int value) {
        if (node == NULL) {
            return false;
        }

        if (node->id == value) {
            return true;
        }

        if (value < node->id) {
            return search(node->left, value);
        }

        return search(node->right, value);
    }
    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }

        return node;
    }
    Node* deleteNode(Node* node, int value, bool& deleted) {
        if (node == NULL) {
            return NULL;
        }

        if (value < node->id) {
            node->left = deleteNode(node->left, value, deleted);
        }
        else if (value > node->id) {
            node->right = deleteNode(node->right, value, deleted);
        }
        else {
            deleted = true;
            if (node->left == NULL &&
                node->right == NULL) {
                delete node;
                return NULL;
            }
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->id = temp->id;

            bool successorDeleted = false;
            node->right = deleteNode(
                node->right, temp->id, successorDeleted
            );
        }

        return node;
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
    void destroyTree(Node* node) {
        if (node == NULL) {
            return;
        }

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }
    ~BST() {
        destroyTree(root);
        root = NULL;
    }
    void insertProduct(int value) {
        bool inserted = false;
        root = insert(root, value, inserted);

        if (inserted) {
            cout << "Product inserted successfully.\n";
        }
        else {
            cout << "Duplicate product ID! Not inserted.\n";
        }
    }
    void searchProduct(int value) {
        if (search(root, value)) {
            cout << "Product Found!\n";
        }
        else {
            cout << "Product Not Found!\n";
        }
    }
    void deleteProduct(int value) {
        bool deleted = false;
        root = deleteNode(root, value, deleted);

        if (deleted) {
            cout << "Product deleted successfully.\n";
        }
        else {
            cout << "Product Not Found! Cannot delete.\n";
        }
    }
    void displayInOrder() {
        if (root == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "In-order: ";
        inOrder(root);
        cout << endl;
    }

    void displayPreOrder() {
        if (root == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "Pre-order: ";
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        if (root == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }

        cout << "Post-order: ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BST inventory;
    int choice, id;

    do {
        cout << "\n===== ONLINE STORE INVENTORY =====\n";
        cout << "1. Insert Product ID\n";
        cout << "2. Search Product ID\n";
        cout << "3. Delete Product ID\n";
        cout << "4. Display In-order Traversal\n";
        cout << "5. Display Pre-order Traversal\n";
        cout << "6. Display Post-order Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID to insert: ";
            cin >> id;
            inventory.insertProduct(id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            inventory.searchProduct(id);
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            inventory.deleteProduct(id);
            break;

        case 4:
            inventory.displayInOrder();
            break;

        case 5:
            inventory.displayPreOrder();
            break;

        case 6:
            inventory.displayPostOrder();
            break;

        case 7:
            cout << "Exiting Inventory System...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
