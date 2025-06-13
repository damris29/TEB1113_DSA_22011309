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
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void display_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void display_reverse() {
        cout << "Reverse order: ";
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->name << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    
    void delete_by_value(string val) {
        if (head == nullptr) return;
        
        Node* current = head;
        
        // Find the node to delete
        while (current != nullptr && current->name != val) {
            current = current->next;
        }
        
        // If node not found
        if (current == nullptr) return;
        
        // If only one node in the list
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        // If deleting the head
        else if (current == head) {
            head = head->next;
            head->prev = nullptr;
        }
        // If deleting the tail
        else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // If deleting a middle node
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        
        delete current;
    }
    
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
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
    
    cout << "Enter a name to delete: ";
    cin >> name;
    linkedlist.delete_by_value(name);
    
    cout << "After deletion: ";
    linkedlist.display_list();
    
    return 0;
}