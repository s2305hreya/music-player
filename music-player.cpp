#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* currentNode = nullptr;

void insert() {
    cout << "Enter Music Name: ";
    cin.ignore();
    string temp;
    getline(cin, temp);

    Node* newNode = new Node();
    newNode->data = temp;

    if (head == nullptr) {
        newNode->next = newNode->prev = newNode;
        head = currentNode = newNode;
        return;
    }

    Node* last = head->prev;
    newNode->prev = last;
    last->next = newNode;
    newNode->next = head;
    head->prev = newNode;
}

void deleteElement() {
    if (head == nullptr) {
        cout << "No Music is there to delete!\n";
        return;
    }

    cout << "Enter Music Name to delete: ";
    cin.ignore();
    string temp;
    getline(cin, temp);

    Node* ptr = head;

    do {
        if (ptr->next == ptr && ptr->data == temp) {
            cout << "One file deleted! Playlist is Empty Now!\n";
            delete ptr;
            head = nullptr;
            return;
        } else if (ptr->data == temp) {
            Node* prev = ptr->prev;
            Node* next = ptr->next;
            prev->next = next;
            next->prev = prev;
            if (ptr == head) head = next;
            delete ptr;
            cout << "Music deleted!\n";
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    cout << "No Music file is there!\n";
}

void show() {
    if (head == nullptr) {
        cout << "Playlist is Empty!\n";
        return;
    }

    Node* showPtr = head;
    int i = 1;
    cout << "\nDisplaying Playlist:\n";
    do {
        cout << "Song " << i++ << ": " << showPtr->data << endl;
        showPtr = showPtr->next;
    } while (showPtr != head);
}

void nextNode() {
    if (currentNode == nullptr) {
        cout << "No songs in Playlist!\n";
    } else {
        currentNode = currentNode->next;
        cout << "Playing Next Song: " << currentNode->data << endl;
    }
}

void prevNode() {
    if (currentNode == nullptr) {
        cout << "No songs in Playlist!\n";
    } else {
        currentNode = currentNode->prev;
        cout << "Playing Previous Song: " << currentNode->data << endl;
    }
}

void firstNode() {
    if (head == nullptr) {
        cout << "Playlist is Empty!\n";
    } else {
        cout << "Playing First Music: " << head->data << endl;
    }
}

void lastNode() {
    if (head == nullptr) {
        cout << "Playlist is Empty!\n";
    } else {
        cout << "Playing Last Music: " << head->prev->data << endl;
    }
}

void specificData() {
    if (head == nullptr) {
        cout << "No music is there to be searched!\n";
        return;
    }

    show();
    cout << "Enter Music to play: ";
    cin.ignore();
    string temp;
    getline(cin, temp);

    Node* ptr = head;
    do {
        if (ptr->data == temp) {
            cout << "Music Found!\nPlaying Music: " << ptr->data << endl;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    cout << "There is no Music file with this name!\n";
}

int main() {
    int choice;
    do {
        cout << "\n----- Song Playlist Application -----\n";
        cout << "1. Add Music\n";
        cout << "2. Remove Music\n";
        cout << "3. Show Playlist\n";
        cout << "4. Play Next Music\n";
        cout << "5. Play Previous Music\n";
        cout << "6. Play First Music\n";
        cout << "7. Play Last Music\n";
        cout << "8. Play Specific Music\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                show();
                break;
            case 4:
                nextNode();
                break;
            case 5:
                prevNode();
                break;
            case 6:
                firstNode();
                break;
            case 7:
                lastNode();
                break;
            case 8:
                specificData();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
