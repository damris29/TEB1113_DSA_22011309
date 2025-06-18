/*
id: 22011309
name: Adam Haris
group: G1
lab : L3
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;
    
    Node(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void add_element(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }
    
    void display_list() {
        if (head == nullptr) {
            cout << "NULL" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->name << endl; // To show circular connection
    }
    
    void display_reverse() {
        if (tail == nullptr) {
            cout << "NULL" << endl;
            return;
        }

        cout << "Reverse order: ";
        Node* temp = tail;
        do {
            cout << temp->name << " -> ";
            temp = temp->prev;
        } while (temp != tail);
        cout << tail->name << endl; // To show circular connection
    }

    
    ~DoublyLinkedList() {
        if (head == nullptr) return;
        Node* temp = head;
        do {

            Node* next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoublyLinkedList linkedlist;
    string name;
    
    for (int i = 0; i < 3; i++) {
        cout << "Enter a name #" << i + 1 << ": ";
        cin >> name;
        linkedlist.add_element(name);
    }
    
    cout << "Initial list: ";
    linkedlist.display_list();
    
    linkedlist.display_reverse();
    
    return 0;
}
