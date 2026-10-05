#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string imageName;
    Node* prev;
    Node* next;

    Node(string name) {
        imageName = name;
        prev = nullptr;
        next = nullptr;
    }
};

int main() {

    Node* first = new Node("Nature.jpg");
    Node* second = new Node("Beach.jpg");
    Node* third = new Node("Mountain.jpg");
    Node* fourth = new Node("City.jpg");
    Node* fifth = new Node("Sunset.jpg");

    
    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    
    cout << "Images (First -> Last):" << endl;

    Node* current = first;

    while (current != nullptr) {
        cout << current->imageName << endl;
        current = current->next;
    }

    
    cout << "\nImages (Last -> First):" << endl;

    current = fifth;

    while (current != nullptr) {
        cout << current->imageName << endl;
        current = current->prev;
    }

    return 0;
}