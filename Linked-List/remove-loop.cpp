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
void removeLoop(Node *&head)
{
    // check for loop
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }

    // yha pahuche iska mtlb slow and fast meet kr chuka h

    slow = head;

    // slow and fast 1 step aage badao
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // starting point
    Node *startPont = slow;

    Node *temp = fast;
    while (temp->next != startPont)
    {
        temp = temp->next;
    }
    temp->next = NULL;
};
int main()
{
    // Creating nodes
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    // Linking nodes normally
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node *head = first;
    // Creating a cycle (linking last node to third node)
    fifth->next = third; // Creates a cycle at node "third"


    removeLoop(head);
 printLL(head);

}