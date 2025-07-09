#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string val) {
        name = val;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Tree definition
class Tree {
private:
    Node* root;

    // Helper function to insert recursively
    Node* add_element(Node* node, string name) {
        if (node == nullptr) {
            return new Node(name);
        }

        if (name < node->name) {
            node->left = add_element(node->left, name);
        } else {
            node->right = add_element(node->right, name);
        }

        return node;
    }

    // Helper function for in-order traversal
    void in_order(Node* node) {
        if (node != nullptr) {
            in_order(node->left);
            cout << node->name << " ";
            in_order(node->right);
        }
    }

public:
    Tree() {
        root = nullptr;
    }

    void add_element(string name) {
        root = add_element(root, name);
    }

    void print_in_order() {
        cout << "In-order Traversal: ";
        in_order(root);
        cout << endl;
    }
};

// Main function
int main() {
    Tree tree;
    tree.add_element("Charlie");
    tree.add_element("Alice");
    tree.add_element("Eve");
    tree.add_element("Bob");
    tree.add_element("David");

    tree.print_in_order();  // Expected order: Alice Bob Charlie David Eve
    
    return 0;
}