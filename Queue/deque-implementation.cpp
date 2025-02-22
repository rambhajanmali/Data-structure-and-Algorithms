#include<iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void pushBack(int val){
        //overflow condition
        //emptyCase => first element
        //circilar case
        //normal case

        if((front == 0 && rear == size -1) || (rear == front -1)){
            cout<<"overflow"<<endl;
        }
        else if(front == -1 && rear == -1){
            //empty case
            front++;
            rear++;
            arr[rear] = val;
        }
        else if(rear == size -1 && front != 0){
            //circular case
            rear = 0;
            arr[rear] = val;
        }
        else{
            //normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pushFront(int val){
        // check if deque is full
        if(front == 0){
            cout<<"deque is full"<<endl;
        }
        else if(front == -1 && rear == -1){
            // empty case
            front++;
            rear++;
            arr[front] = val;
        }
        else if(front == 0 && rear != size - 1){
            // circular case
            front = size - 1;
            arr[front] = val;
        }
        else{
            // normal case
            front--;
            arr[front] = val;
        }
    }

    void popFront(){
       //underflow condition
        //single element
        //circular case
        //normal case

        if(front == -1 && rear == -1){
            cout<<"underflow"<<endl;
        }
        else if(front == rear){
            //only one element
            arr[front] = -1;
            front = -1;
            rear = -1;
            
        }
        else if(front == size -1){
            //circular case
            arr[front] = -1;
            front = 0;
        }
        else{
            //normal case
            arr[front] = -1;
            front++;
        }
    }
    void popBack(){
        // check if queue is empty
        if(front == -1 && rear == -1){
            cout<<"queue is empty"<<endl;
            return;
        }
        else if(front == rear){
            // only one element
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
            // circular case
            arr[rear] = -1;
            rear = size - 1;
        }
        else{
            // normal case
            arr[rear] = -1; 
            rear--;
        }
    }
};
int main(){
    Deque dq(5);

    return 0;
}