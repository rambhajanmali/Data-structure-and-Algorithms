#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(){
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int findLength(Node* head){
    Node* temp = head; 
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    cout<<"Length of the linked list is: "<<len<<endl;
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    //LL is empty
if(head == NULL){
Node* newNode = new Node(data);
head = newNode;
tail = newNode;
}
else{
    //LL is not empty
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
}

void insertAtTail(Node* &head, Node* &tail, int data){
    //LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data,int position){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        int len = findLength(head);
        if(position == 1){
            insertAtHead(head,tail,data);
        }
        else if(position == len+1){
            insertAtTail(head,tail,data);
        }
        else{
            //inser in middle
            //step1: create a new node
            Node* newNode = new Node(data);
            //step2: set prev and curr pointers
            Node* prevNode = NULL;
            Node* currNode = head;
            while(position != 1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            //step3 : pointers update kare the
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(head == NULL){
        //LL is empty
        cout<<"Cannot delete, coz LL is empty"<<endl;
        return;
    }

    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }


    int len = findLength(head);

    if(position == 1){
        //delete from head
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == len){
        //delete from tail
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        //delete from middle
       //step1: set prevNode/currNode/nextNode pointers
         Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;
    }
    
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    print(head);
    cout<<endl;


    // insertAtPosition(head,tail,100,2);
    // insertAtTail(head,tail,40);

    deleteNode(head,tail,3);
    print(head);

    // Node* head = new Node(10);
    return 0;
}