
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

struct Patient {
    string id;
    int priority;
};

class PriorityQueue {
private:
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }
    void enqueue(string id, int priority) {
        if (count == SIZE) {
            cout << "Queue Overflow! Queue is full.\n";
            return;
        }

        Patient newPatient;
        newPatient.id = id;
        newPatient.priority = priority;

        int i = count - 1;
        while (i >= 0 &&
               patients[i].priority > newPatient.priority) {
            patients[i + 1] = patients[i];
            i--;
        }

        patients[i + 1] = newPatient;
        count++;

        cout << "Patient " << id << " added successfully.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty. No patient to treat.\n";
            return;
        }

        cout << "Treating patient: " << patients[0].id
             << " (Priority " << patients[0].priority << ")\n";

        for (int i = 0; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No patients are waiting.\n";
            return;
        }

        cout << "\nWaiting Patients:\n";

        for (int i = 0; i < count; i++) {
            cout << "Patient ID: " << patients[i].id
                 << ", Priority: " << patients[i].priority
                 << endl;
        }
    }
};

int main() {
    PriorityQueue q;
    int choice, priority;
    string id;

    do {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Priority (1 = Highest): ";
            cin >> priority;

            if (priority < 1) {
                cout << "Invalid priority! Use 1 or greater.\n";
                break;
            }

            q.enqueue(id, priority);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
