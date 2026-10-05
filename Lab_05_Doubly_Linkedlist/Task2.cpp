#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string playerName;
    Node* next;

    Node(string name) {
        playerName = name;
        next = nullptr;
    }
};

int main() {

    Node* first = new Node("Ali");
    Node* second = new Node("Ahmed");
    Node* third = new Node("Usman");
    Node* fourth = new Node("Hamza");
    Node* fifth = new Node("Musa");

    
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    
    fifth->next = first;

    
    cout << "Player Turns:" << endl;

    Node* current = first;

    for (int i = 0; i < 5; i++) {
        cout << current->playerName << "'s turn" << endl;
        current = current->next;
    }

    
    cout << "\nAfter the last player:" << endl;
    cout << current->playerName << "'s turn" << endl;

    return 0;
}