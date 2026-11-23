
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class StudentNode {
public:
    string name;
    int rollNo;
    int marks;
    StudentNode* left;
    StudentNode* right;

    StudentNode(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = right = NULL;
    }
};

class StudentHeap {
private:
    StudentNode* root;

    // Swap student information only
    void swapData(StudentNode* a, StudentNode* b) {
        swap(a->name, b->name);
        swap(a->rollNo, b->rollNo);
        swap(a->marks, b->marks);
    }

    // Find parent of a node using Level Order Traversal
    StudentNode* findParent(StudentNode* target) {
        if (root == NULL || root == target)
            return NULL;

        queue<StudentNode*> q;
        q.push(root);

        while (!q.empty()) {
            StudentNode* current = q.front();
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
    void heapifyUp(StudentNode* node) {
        while (node != root) {
            StudentNode* parent = findParent(node);

            if (parent == NULL || node->marks <= parent->marks)
                break;

            swapData(node, parent);
            node = parent;
        }
    }

    // Heapify Down
    void heapifyDown(StudentNode* node) {
        while (node != NULL) {
            StudentNode* largest = node;

            if (node->left != NULL &&
                node->left->marks > largest->marks) {
                largest = node->left;
            }

            if (node->right != NULL &&
                node->right->marks > largest->marks) {
                largest = node->right;
            }

            if (largest == node)
                break;

            swapData(node, largest);
            node = largest;
        }
    }

public:
    StudentHeap() {
        root = NULL;
    }

    // Insert student at the next available position
    void insert(string name, int rollNo, int marks) {
        StudentNode* newNode = new StudentNode(name, rollNo, marks);

        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<StudentNode*> q;
        q.push(root);

        while (!q.empty()) {
            StudentNode* current = q.front();
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

    // Display Heap using Level Order Traversal
    void display() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        queue<StudentNode*> q;
        q.push(root);

        cout << "\nStudent Heap (Level Order):\n";

        while (!q.empty()) {
            StudentNode* current = q.front();
            q.pop();

            cout << "Name: " << current->name
                 << " | Roll No: " << current->rollNo
                 << " | Marks: " << current->marks << endl;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }

    // Display student having maximum marks
    void displayTopStudent() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "\nHighest Merit Student:\n";
        cout << "Name: " << root->name << endl;
        cout << "Roll No: " << root->rollNo << endl;
        cout << "Marks: " << root->marks << endl;
    }

    // Delete student with maximum marks
    void deleteMax() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "\nDeleting highest marks student: "
             << root->name << " (" << root->marks << ")" << endl;

        // If heap has only one node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return;
        }

        queue<StudentNode*> q;
        q.push(root);

        StudentNode* last = NULL;
        StudentNode* lastParent = NULL;

        // Find the last node in Level Order
        while (!q.empty()) {
            StudentNode* current = q.front();
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

        // Replace root's data with last node's data
        swapData(root, last);

        // Remove last node from tree
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
    StudentHeap heap;

    // Insert six students
    heap.insert("Ali", 101, 85);
    heap.insert("Ahmed", 102, 92);
    heap.insert("Sara", 103, 78);
    heap.insert("Musa", 104, 95);
    heap.insert("Ayesha", 105, 88);
    heap.insert("Hamza", 106, 81);

    cout << "===== UNIVERSITY STUDENT MERIT HEAP =====";

    heap.display();

    heap.displayTopStudent();

    heap.deleteMax();

    cout << "\nHeap after deleting highest marks student:";
    heap.display();

    heap.displayTopStudent();

    return 0;
}
