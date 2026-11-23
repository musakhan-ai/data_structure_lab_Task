
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

class MedicineNode {
public:
    string name;
    int medicineID;
    int expiryDate;
    MedicineNode* left;
    MedicineNode* right;

    MedicineNode(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = right = NULL;
    }
};

class MedicineHeap {
private:
    MedicineNode* root;

    // Swap medicine information
    void swapData(MedicineNode* a, MedicineNode* b) {
        swap(a->name, b->name);
        swap(a->medicineID, b->medicineID);
        swap(a->expiryDate, b->expiryDate);
    }

    // Find parent of a node
    MedicineNode* findParent(MedicineNode* target) {
        if (root == NULL || root == target)
            return NULL;

        queue<MedicineNode*> q;
        q.push(root);

        while (!q.empty()) {
            MedicineNode* current = q.front();
            q.pop();

            if (current->left == target ||
                current->right == target)
                return current;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        return NULL;
    }

    // Heapify Up for Min Heap
    void heapifyUp(MedicineNode* node) {
        while (node != root) {
            MedicineNode* parent = findParent(node);

            if (parent == NULL ||
                node->expiryDate >= parent->expiryDate)
                break;

            swapData(node, parent);
            node = parent;
        }
    }

    // Heapify Down for Min Heap
    void heapifyDown(MedicineNode* node) {
        while (node != NULL) {
            MedicineNode* smallest = node;

            if (node->left != NULL &&
                node->left->expiryDate < smallest->expiryDate)
                smallest = node->left;

            if (node->right != NULL &&
                node->right->expiryDate < smallest->expiryDate)
                smallest = node->right;

            if (smallest == node)
                break;

            swapData(node, smallest);
            node = smallest;
        }
    }

public:
    MedicineHeap() {
        root = NULL;
    }

    // Insert medicine
    void insert(string name, int id, int date) {
        MedicineNode* newNode = new MedicineNode(name, id, date);

        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<MedicineNode*> q;
        q.push(root);

        while (!q.empty()) {
            MedicineNode* current = q.front();
            q.pop();

            if (current->left == NULL) {
                current->left = newNode;
                heapifyUp(newNode);
                return;
            }
            else {
                q.push(current->left);
            }

            if (current->right == NULL) {
                current->right = newNode;
                heapifyUp(newNode);
                return;
            }
            else {
                q.push(current->right);
            }
        }
    }

    // Level Order Traversal
    void display() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        queue<MedicineNode*> q;
        q.push(root);

        cout << "\nMedicines in Level Order:\n";

        while (!q.empty()) {
            MedicineNode* current = q.front();
            q.pop();

            cout << "Medicine: " << current->name
                 << " | ID: " << current->medicineID
                 << " | Expiry: " << current->expiryDate << endl;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }

    // Display medicine with nearest expiry date
    void displayNearestExpiry() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "\nMedicine with Nearest Expiry:\n";
        cout << "Name: " << root->name << endl;
        cout << "Medicine ID: " << root->medicineID << endl;
        cout << "Expiry Date: " << root->expiryDate << endl;
    }

    // Delete medicine with nearest expiry
    void deleteMin() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "\nRemoving medicine with nearest expiry: "
             << root->name << " (" << root->expiryDate << ")" << endl;

        // If only one node exists
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return;
        }

        queue<MedicineNode*> q;
        q.push(root);

        MedicineNode* last = NULL;
        MedicineNode* lastParent = NULL;

        // Find last node in Level Order
        while (!q.empty()) {
            MedicineNode* current = q.front();
            q.pop();

            if (current->left) {
                lastParent = current;
                last = current->left;
                q.push(current->left);
            }

            if (current->right) {
                lastParent = current;
                last = current->right;
                q.push(current->right);
            }
        }

        // Move last node's data to root
        swapData(root, last);

        // Remove last node
        if (lastParent->right == last)
            lastParent->right = NULL;
        else
            lastParent->left = NULL;

        delete last;

        // Restore Min Heap
        heapifyDown(root);
    }
};

int main() {
    MedicineHeap heap;

    // Insert six medicines
    heap.insert("Paracetamol", 301, 20271215);
    heap.insert("Amoxicillin", 302, 20270310);
    heap.insert("Ibuprofen", 303, 20261130);
    heap.insert("Vitamin C", 304, 20280520);
    heap.insert("Cough Syrup", 305, 20261205);
    heap.insert("Antacid", 306, 20270618);

    cout << "===== HOSPITAL MEDICINE MIN HEAP =====";

    heap.display();

    heap.displayNearestExpiry();

    heap.deleteMin();

    cout << "\nHeap after deleting nearest expiry medicine:";
    heap.display();

    heap.displayNearestExpiry();

    return 0;
}
