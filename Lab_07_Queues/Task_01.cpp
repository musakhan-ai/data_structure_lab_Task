
#include <iostream>
using namespace std;

const int SIZE = 5;

class BankQueue {
private:
    int customers[SIZE];
    int front, rear;

public:
    
    BankQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! No space available.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        customers[rear] = token;

        cout << "Customer " << token
             << " added to the queue.\n";
    }
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! No customers to serve.\n";
            return;
        }

        cout << "Customer " << customers[front]
             << " has been served.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No customers are waiting.\n";
            return;
        }

        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++) {
            cout << customers[i] << " ";
        }

        cout << endl;
    }
    void countCustomers() {
        if (front == -1) {
            cout << "Number of waiting customers: 0\n";
        } else {
            cout << "Number of waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main() {
    BankQueue q;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service System ---\n";
        cout << "1. Add Customer (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Count Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer token number: ";
            cin >> token;
            q.enqueue(token);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.countCustomers();
            break;

        case 5:
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
