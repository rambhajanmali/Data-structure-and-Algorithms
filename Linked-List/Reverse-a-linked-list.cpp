#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    // Default constructor
    Node() {
        this->data ; 
        this->next ;
    }

    // Parameterized constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print the linked list
void printLL(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse the linked list
Node *reverseList(Node *head) {
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL) {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main() {
    Node a; // Calls the default constructor
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Linking nodes
    first->next = second;
    second->next = third;

    // Head of linked list
    Node *head = first;

    cout << "Original Linked List:" << endl;
    printLL(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed Linked List:" << endl;
    printLL(head);

    return 0;
}
