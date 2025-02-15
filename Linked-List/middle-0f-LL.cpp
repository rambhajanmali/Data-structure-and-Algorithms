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
    int getLength(Node* head){
            int len = 0;
            Node* temp = head;
            while(temp != NULL){
                len++;
                temp = temp->next;
            }
            return len;
    }
    
        Node* middleNode(Node* head) {
    
            //using trotter approach
            Node* slow = head;
              Node* fast = head;
              while(fast != NULL){
                fast = fast->next;
    
                if(fast != NULL){
                    fast = fast->next;
                    //i can say that fast 2 step aage aa gya h
                    //now slow can go 1 step 
                    slow = slow->next;
                }
              }
               return slow;
    
               //without trotter approach
    
            // int n = getLength(head);
            // int position = n/2 +1;
    
            // ListNode* temp = head;
            // while(position != 1){
            //     position --;
            //     temp = temp->next;
            // }
            // return temp;
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
        
            cout << "Middle Node: " << middleNode(head)->data << endl;
        
            return 0;
        };
  