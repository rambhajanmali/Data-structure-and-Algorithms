#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int val){
        // check if queue is full
        if(rear == size - 1){
            cout<<"queue is full"<<endl;
        }
        else if(front == -1 && rear == -1){
            //empty case
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            //normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        // check if queue is empty
        if(front == -1 && rear == -1){
            cout<<"queue is empty"<<endl;
            return;
        }
        else if(front == rear){
            // only one element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else{
            // normal case
            arr[front] = -1; 
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }else{
            return rear - front + 1;
        }   
    }

    int getFront(){
        if(front == -1){
            cout<<"queue is empty, cannot give front element"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
       
    }
    int getRear(){
        if(rear == -1){
            cout<<"queue is empty, cannot give rear element"<<endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    void print(){
        cout<< "printing queue"<<endl;
        for(int i = 0; i< size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){

    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();

    cout<<"size of the queue is: " <<q.getSize();

    q.pop();

    q.pop();
    q.pop();
    q.print();
    cout<<"size of the queue is: " <<q.getSize();
cout<<endl;

q.push(60);
    cout<<"front element of the queue is: "<<q.getFront();
    return 0;
}