#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
private:
    string* pages;   
    int top;         
    int capacity;    
public:
    // Constructor
    BrowserHistory(int size = 10) {
        capacity = size;
        pages = new string[capacity];
        top = -1;
    }

    // Destructor
    ~BrowserHistory() {
        delete[] pages;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }
    void push(const string& page) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot add " << page << endl;
            return;
        }
        pages[++top] = page;
        cout << "Visited: " << page << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No page to go back from." << endl;
            return;
        }
        cout << "Back pressed. Removed page: " << pages[top] << endl;
        top--;
    }
    string peek() const {
        if (isEmpty()) return "No page";
        return pages[top];
    }
    void display() const {
        if (isEmpty()) {
            cout << "History is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << "  " << pages[i];
            if (i == top) cout << "  (TOP)";
            cout << endl;
        }
    }
};

int main() {
    BrowserHistory browser(10);
    cout << " Visiting Pages:" << endl;
    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    cout << "\n Browsing History (TOP to Bottom):" << endl;
    browser.display();

    cout << "\n Pressing Back Button:" << endl;
    browser.pop();

    cout << "\n Current Page:" << endl;
    cout << "Current TOP page: " << browser.peek() << endl;

    cout << "\n Remaining Browsing History:" << endl;
    browser.display();

    return 0;
}