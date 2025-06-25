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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // Push: Insert at top
    void push(string name) {
        Node* newNode = new Node(name);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top->prev = newNode;
            top = newNode;
        }
    }

    // Pop: Remove from top
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to pop." << endl;
            return;
        }

        cout << "Popped: " << top->name << endl;
        Node* temp = top;
        top = top->next;
        if (top != nullptr) {
            top->prev = nullptr;
        }
        delete temp;
    }

    // Peek: Show the top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top of stack: " << top->name << endl;
        }
    }

    // Display: From top to bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "\nStack (Top to Bottom): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->name;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack myStack;
    string name;

    myStack.push("Alice");
    myStack.push("Bob");
    myStack.push("Charlie");

    myStack.display(); 
    myStack.peek();    

    myStack.pop();     
    myStack.display(); 
    myStack.peek();    

    return 0;
}
