#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    string songName;
    Node* next;

    Node(string name) {
        songName = name;
        next = nullptr;
    }
};

int main() {

    Node* first = new Node("Believer");
    Node* second = new Node("Perfect");
    Node* third = new Node("Shape of You");
    Node* fourth = new Node("Faded");
    Node* fifth = new Node("Despacito");

    
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    
    fifth->next = first;

    
    cout << "Music Playlist:" << endl;

    Node* current = first;

    for (int i = 0; i < 5; i++) {
        cout << current->songName << endl;
        current = current->next;
    }

    
    cout << "\nPlaying Playlist for 2 Rounds:" << endl;

    current = first;

    for (int i = 1; i <= 10; i++) {

        cout << "Playing: " << current->songName << endl;

        current = current->next;
    }

    return 0;
}