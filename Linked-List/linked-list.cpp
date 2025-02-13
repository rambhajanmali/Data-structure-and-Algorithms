#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        cout<<"I am inside default constructor"<<endl;
        this->next = NULL;
    }

    Node(int data){
        // cout<<"I am inside parameter constructor"<<endl;
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int getlength(Node* head){
    Node* temp = head;
    int count  =0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head,Node* &tail, int data){
    if(head == NULL){
        //empty LL
        //step 1: create a new node
        Node* newNode =  new Node(data);
        //step2 : update head 
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        //step 1: create a new node
        Node* newNode = new Node(data);
        //step2: attach new node to head node
        newNode->next = head;
        //step3: update head
        head = newNode;
    }
}

 void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        //empty LL
        //step 1: create a new node
        Node* newNode =  new Node(data);
        //step2 : single mode h entire list me,
        //thats why head and tail ko is pr point kr do
        head = newNode;
        tail = newNode;
    }
    else{
        //LL is not empty
        //step 1: create a new node
        Node* newNode = new Node(data);
        //step2: attach new node to tail node
        tail->next = newNode;
        //step3: update tail
        tail = newNode;
    }
}

void createTail(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    //jab ye loop khatam hoga then apka temp wala pointer last node pr hoga tab tail = temp krke tail ko last node pr le aao
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
 
  int length = getlength(head);

  if(position == 1){
    insertAtHead(head,tail,data);
  }
  else if(position == length+1){
    insertAtTail(head,tail,data);
  }
  else{
   //insert at middle of linked list
   //step 1: create a new node
    Node* newNode = new Node(data);
    //step2: traverse prev // curr to position
    Node* prev = NULL;
    Node* curr = head;
    while(position !=1){
        prev = curr;
        curr = curr->next;
        position--;
    }
    //step3: attach  prev to new node
    prev->next = newNode;
    //attach new node to curr
    newNode->next = curr;

  }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    // printLL(head);
    insertAtPosition(head,tail,25,3);
    printLL(head);

    // //creation of node
    // // Node a;
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);


    // first->next = second;
    // second->next = third;
    // //linkded list create ho chuki hai

    // Node * head = first;
    // cout<<"print the entire LL"<<endl;
    // printLL(head);

    // Node* tail = third;
    // // insertAtHead(head,tail,55);
    // // printLL(head);

    // insertAtTail(head,tail,40);
    // printLL(head);

    // // cout<<"length of LL is :"<<getlength(head)<<endl;
}