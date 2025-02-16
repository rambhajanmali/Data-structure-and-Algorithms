#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        this->data;
        this->next;
    }

    // Parameterized constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print the linked list
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse the linked list
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addOne(Node* &head)
{
    // reverse
    head = reverseList(head);
    // add 1
    int carry = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        temp = temp->next;
        if (carry == 0)
        {
            break;
        }
    }

    // process last node
    if (carry != 0)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        if (carry != 0)
        {
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }
       // reverse
       head = reverseList(head);
}

    int main()
    {
        Node a; // Calls the default constructor
        Node *first = new Node(9);
        Node *second = new Node(9);
        Node *third = new Node(9);

        // Linking nodes
        first->next = second; 
        second->next = third;

        // Head of linked list
        Node *head = first;

        cout << "Original Linked List:" << endl;
        printLL(head);

        cout<<endl;
        addOne(head);
        printLL(head);
        cout<<endl;
    

        return 0;
    }
