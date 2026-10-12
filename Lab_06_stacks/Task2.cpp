#include <iostream>
#include <string>
using namespace std;

class UndoStack {
private:
    string* actions;   
    int top;          
    int capacity;      

public:
    // Constructor
    UndoStack(int size = 10) {
        capacity = size;
        actions = new string[capacity];
        top = -1;
    }

    // Destructor
    ~UndoStack() {
        delete[] actions;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    void push(const string& action) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot record: " << action << endl;
            return;
        }
        actions[++top] = action;
        cout << "Action recorded: " << action << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to undo." << endl;
            return;
        }
        cout << "Undo: " << actions[top] << endl;
        top--;
    }

    string peek() const {
        if (isEmpty()) return "No action";
        return actions[top];
    }

    void display() const {
        if (isEmpty()) {
            cout << "No actions recorded." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << "  " << actions[i];
            if (i == top) cout << "  (TOP)";
            cout << endl;
        }
    }
};

int main() {
    UndoStack editor(10);

    cout << "--- Performing Actions ---" << endl;
    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");

    cout << "\n All Actions (TOP to Bottom): " << endl;
    editor.display();

    cout << "\n Performing Undo (x2): " << endl;
    editor.pop();
    editor.pop();

    cout << "\n Current TOP Action: " << endl;
    cout << "Current TOP action: " << editor.peek() << endl;

    // 5. Display remaining actions
    cout << "\n Remaining Actions: " << endl;
    editor.display();

    return 0;
}