#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
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
            tail = newNode;
        }
    }

    void display_list() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string val) {
        if (head == nullptr) return;

        // If the head needs to be deleted
        if (head->name == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->name != val) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = temp->next;

        // If we deleted the tail
        if (temp == tail) {
            tail = current;
        }

        delete temp;
    }
};

int main() {
    LinkedList linkedlist;

    string name;
    for (int i = 0; i < 3; i++) {
        cout << "Enter a name #" << i + 1 << ": ";
        cin >> name;
        linkedlist.add_element(name);
    }

    cout << "Initial list: ";
    linkedlist.display_list();

    cout << "Enter a name to delete: ";
    cin >> name;
    linkedlist.delete_by_value(name);

    cout << "After deletion: ";
    linkedlist.display_list();

    return 0;
}
