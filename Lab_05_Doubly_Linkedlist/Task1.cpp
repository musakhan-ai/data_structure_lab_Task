#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = nullptr;
        next = nullptr;
    }
};

int main() {

    Node* first = new Node("Google");
    Node* second = new Node("YouTube");
    Node* third = new Node("GitHub");
    Node* fourth = new Node("Facebook");
    Node* fifth = new Node("ChatGPT");

    
    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    
    cout << "Browser History (First -> Last):" << endl;

    Node* current = first;

    while (current != nullptr) {
        cout << current->website << endl;
        current = current->next;
    }

    
    cout << "\nBrowser History (Last -> First):" << endl;

    current = fifth;

    while (current != nullptr) {
        cout << current->website << endl;
        current = current->prev;
    }

    return 0;
}