#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string requestID;
    Node* next;

    Node(const string& id) {
        requestID = id;
        next = nullptr;
    }
};

class EmergencyStack {
private:
    Node* top;  

public:
    // Constructor
    EmergencyStack() {
        top = nullptr;
    }

    // Destructor: free all remaining nodes
    ~EmergencyStack() {
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
        cout << "Request received: " << id << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No requests to handle." << endl;
            return;
        }
        Node* temp = top;
        cout << "Handling request: " << temp->requestID << endl;
        top = top->next;
        delete temp;
    }

    string peek() const {
        if (isEmpty()) return "No request";
        return top->requestID;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No pending requests." << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << "  " << current->requestID;
            if (current == top) cout << "  (TOP)";
            cout << endl;
            current = current->next;
        }
    }
};

int main() {
    EmergencyStack hospital;

    cout << " Receiving Requests: " << endl;
    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    cout << "\n All Requests (TOP to Bottom): " << endl;
    hospital.display();


    cout << "\n Handling Latest Request: " << endl;
    hospital.pop();

    cout << "\n New TOP Request: " << endl;
    cout << "Current TOP request: " << hospital.peek() << endl;

    cout << "\n Remaining Requests: " << endl;
    hospital.display();

    return 0;
}