
#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
private:
    int requests[SIZE];
    int front, rear, count;

public:
    // Constructor
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }
    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! It is full.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        requests[front] = id;
        count++;

        cout << "Request " << id
             << " inserted at the front.\n";
    }
    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! It is full.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        requests[rear] = id;
        count++;

        cout << "Request " << id
             << " inserted at the rear.\n";
    }
    void deleteFront() {
        if (count == 0) {
            cout << "Deque Underflow! It is empty.\n";
            return;
        }

        cout << "Request " << requests[front]
             << " removed from the front.\n";

        if (count == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        count--;
    }
    void deleteRear() {
        if (count == 0) {
            cout << "Deque Underflow! It is empty.\n";
            return;
        }

        cout << "Request " << requests[rear]
             << " removed from the rear.\n";

        if (count == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }

        count--;
    } 
    void display() {
        if (count == 0) {
            cout << "No passenger requests available.\n";
            return;
        }

        cout << "Passenger requests: ";

        for (int i = 0; i < count; i++) {
            cout << requests[(front + i) % SIZE] << " ";
        }

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, id;

    do {
        cout << "\n--- Train Station Passenger Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter request ID: ";
            cin >> id;
            d.insertFront(id);
            break;

        case 2:
            cout << "Enter request ID: ";
            cin >> id;
            d.insertRear(id);
            break;

        case 3:
            d.deleteFront();
            break;

        case 4:
            d.deleteRear();
            break;

        case 5:
            d.display();
            break;

        case 6:
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
