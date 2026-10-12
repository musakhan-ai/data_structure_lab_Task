#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string orderID;
    Node* next;

    Node(const string& id) {
        orderID = id;
        next = nullptr;
    }
};
class OrderStack {
private:
    Node* top;  

public:
    // Constructor
    OrderStack() {
        top = nullptr;
    }

    // Destructor
    ~OrderStack() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    
    void push(const string& id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
        cout << "Order received: " << id << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No orders to process." << endl;
            return;
        }
        Node* temp = top;
        cout << "Processing order: " << temp->orderID << endl;
        top = top->next;
        delete temp;
    }
    string peek() const {
        if (isEmpty()) return "No order";
        return top->orderID;
    }
    void display() const {
        if (isEmpty()) {
            cout << "No pending orders." << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << "  " << current->orderID;
            if (current == top) cout << "   (TOP)";
            cout << endl;
            current = current->next;
        }
    }
};

int main() {
    OrderStack restaurant;
    cout << " Receiving Orders :" << endl;
    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");
    cout << "\n All Orders (TOP to Bottom) :" << endl;
    restaurant.display();

    cout << "\n Processing Orders (x2) :" << endl;
    restaurant.pop();
    restaurant.pop();

    cout << "\n Current TOP Order :" << endl;
    cout << "Current TOP order: " << restaurant.peek() << endl;

    cout << "\n Remaining Orders :" << endl;
    restaurant.display();

    cout << "\n Is Stack Empty? " << endl;
    if (restaurant.isEmpty())
        cout << "Yes, the stack is empty." << endl;
    else
        cout << "No, the stack is not empty." << endl;

    return 0;
}