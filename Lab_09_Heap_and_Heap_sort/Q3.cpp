
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

class OrderNode {
public:
    int orderID;
    string customerName;
    double amount;
    OrderNode* left;
    OrderNode* right;

    OrderNode(int id, string name, double amt) {
        orderID = id;
        customerName = name;
        amount = amt;
        left = right = NULL;
    }
};

class OrderHeap {
private:
    OrderNode* root;

    // Swap order information
    void swapData(OrderNode* a, OrderNode* b) {
        swap(a->orderID, b->orderID);
        swap(a->customerName, b->customerName);
        swap(a->amount, b->amount);
    }

    // Find parent of a node
    OrderNode* findParent(OrderNode* target) {
        if (root == NULL || root == target)
            return NULL;

        queue<OrderNode*> q;
        q.push(root);

        while (!q.empty()) {
            OrderNode* current = q.front();
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

    // Heapify Up
    void heapifyUp(OrderNode* node) {
        while (node != root) {
            OrderNode* parent = findParent(node);

            if (parent == NULL || node->amount <= parent->amount)
                break;

            swapData(node, parent);
            node = parent;
        }
    }

    // Heapify Down
    void heapifyDown(OrderNode* node) {
        while (node != NULL) {
            OrderNode* largest = node;

            if (node->left != NULL &&
                node->left->amount > largest->amount)
                largest = node->left;

            if (node->right != NULL &&
                node->right->amount > largest->amount)
                largest = node->right;

            if (largest == node)
                break;

            swapData(node, largest);
            node = largest;
        }
    }

    // Delete root and return its amount
    double deleteMax() {
        if (root == NULL)
            return -1;

        double maxAmount = root->amount;

        // Only one node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return maxAmount;
        }

        queue<OrderNode*> q;
        q.push(root);

        OrderNode* last = NULL;
        OrderNode* lastParent = NULL;

        // Find last node in level order
        while (!q.empty()) {
            OrderNode* current = q.front();
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

        // Restore Max Heap
        heapifyDown(root);

        return maxAmount;
    }

public:
    OrderHeap() {
        root = NULL;
    }

    // Insert order
    void insert(int id, string name, double amount) {
        OrderNode* newNode = new OrderNode(id, name, amount);

        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<OrderNode*> q;
        q.push(root);

        while (!q.empty()) {
            OrderNode* current = q.front();
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

    // Display heap
    void display() {
        if (root == NULL) {
            cout << "Heap is empty." << endl;
            return;
        }

        queue<OrderNode*> q;
        q.push(root);

        cout << "\nOrders in Level Order:\n";

        while (!q.empty()) {
            OrderNode* current = q.front();
            q.pop();

            cout << "Order ID: " << current->orderID
                 << " | Customer: " << current->customerName
                 << " | Amount: " << current->amount << endl;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }

    // Heap Sort using repeated root deletion
    void heapSort() {
        double sorted[100];
        int count = 0;

        cout << "\nDeleting Orders from Max Heap:\n";

        while (root != NULL) {
            double amount = deleteMax();
            sorted[count] = amount;
            count++;

            cout << amount << " ";
        }

        cout << "\n\nOrder Amounts in Ascending Order:\n";

        // Reverse the descending array
        for (int i = count - 1; i >= 0; i--) {
            cout << sorted[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    OrderHeap heap;

    // Insert six orders
    heap.insert(501, "Ali", 2500);
    heap.insert(502, "Ahmed", 1200);
    heap.insert(503, "Sara", 4500);
    heap.insert(504, "Musa", 3200);
    heap.insert(505, "Ayesha", 1800);
    heap.insert(506, "Hamza", 6000);

    cout << "===== ONLINE SHOPPING ORDER HEAP =====";

    heap.display();

    heap.heapSort();

    return 0;
}
