#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() {
        front = rear = nullptr;
    }
   
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            cout << value << " enqueued to queue." << endl;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout << value << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued from queue." << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

  
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

   
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
