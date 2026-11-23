
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

class PatientNode {
public:
    string name;
    int patientID;
    int priority;
    PatientNode* left;
    PatientNode* right;

    PatientNode(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = right = NULL;
    }
};

class PatientHeap {
private:
    PatientNode* root;

    // Swap patient information
    void swapData(PatientNode* a, PatientNode* b) {
        swap(a->name, b->name);
        swap(a->patientID, b->patientID);
        swap(a->priority, b->priority);
    }

    // Find parent of a node
    PatientNode* findParent(PatientNode* target) {
        if (root == NULL || root == target)
            return NULL;

        queue<PatientNode*> q;
        q.push(root);

        while (!q.empty()) {
            PatientNode* current = q.front();
            q.pop();

            if (current->left == target ||
                current->right == target) {
                return current;
            }

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        return NULL;
    }

    // Heapify Up
    void heapifyUp(PatientNode* node) {
        while (node != root) {
            PatientNode* parent = findParent(node);

            if (parent == NULL ||
                node->priority <= parent->priority)
                break;

            swapData(node, parent);
            node = parent;
        }
    }

    // Heapify Down
    void heapifyDown(PatientNode* node) {
        while (node != NULL) {
            PatientNode* largest = node;

            if (node->left != NULL &&
                node->left->priority > largest->priority) {
                largest = node->left;
            }

            if (node->right != NULL &&
                node->right->priority > largest->priority) {
                largest = node->right;
            }

            if (largest == node)
                break;

            swapData(node, largest);
            node = largest;
        }
    }

public:
    PatientHeap() {
        root = NULL;
    }

    // Insert patient into Max Heap
    void insert(string name, int id, int priority) {
        PatientNode* newNode = new PatientNode(name, id, priority);

        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<PatientNode*> q;
        q.push(root);

        while (!q.empty()) {
            PatientNode* current = q.front();
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
            cout << "No patients in the heap." << endl;
            return;
        }

        queue<PatientNode*> q;
        q.push(root);

        cout << "\nPatients in Level Order:\n";

        while (!q.empty()) {
            PatientNode* current = q.front();
            q.pop();

            cout << "Name: " << current->name
                 << " | Patient ID: " << current->patientID
                 << " | Priority: " << current->priority << endl;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }

    // Identify highest priority patient
    void displayHighestPriority() {
        if (root == NULL) {
            cout << "No patients in the heap." << endl;
            return;
        }

        cout << "\nPatient with Highest Priority:\n";
        cout << "Name: " << root->name << endl;
        cout << "Patient ID: " << root->patientID << endl;
        cout << "Priority: " << root->priority << endl;
    }

    // Delete highest priority patient after treatment
    void deleteMax() {
        if (root == NULL) {
            cout << "No patients to remove." << endl;
            return;
        }

        cout << "\nPatient treated and removed: "
             << root->name
             << " (Priority " << root->priority << ")" << endl;

        // If only one node exists
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return;
        }

        queue<PatientNode*> q;
        q.push(root);

        PatientNode* last = NULL;
        PatientNode* lastParent = NULL;

        // Find the last node using Level Order Traversal
        while (!q.empty()) {
            PatientNode* current = q.front();
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

        // Restore Max Heap property
        heapifyDown(root);
    }
};

int main() {
    PatientHeap heap;

    // Insert six patients
    heap.insert("Ali", 201, 4);
    heap.insert("Ahmed", 202, 9);
    heap.insert("Sara", 203, 6);
    heap.insert("Musa", 204, 10);
    heap.insert("Ayesha", 205, 7);
    heap.insert("Hamza", 206, 3);

    cout << "===== HOSPITAL EMERGENCY MAX HEAP =====";

    heap.display();

    heap.displayHighestPriority();

    heap.deleteMax();

    cout << "\nHeap after treating highest priority patient:";
    heap.display();

    heap.displayHighestPriority();

    return 0;
}
