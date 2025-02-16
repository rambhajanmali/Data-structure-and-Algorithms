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
Node *deleteDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->data == temp->next->data)
        {
            // remove
            Node *nextNode = temp->next;
            temp->next = nextNode->next;
            nextNode->next = NULL;
            delete nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    // Creating nodes
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(20);
    Node *fourth = new Node(30);
    Node *fifth = new Node(50);

    // Linking nodes normally
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node *head = first;
    cout << "before removal" << endl;
    printLL(head);
    head = deleteDuplicates(head);
    cout << "after removal" << endl;
    printLL(head);
}
