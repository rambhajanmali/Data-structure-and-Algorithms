#include<iostream>
using namespace std;

class Cqueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int size){
        arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int val){
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

    void pop(){
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

    void print(){
        cout<< "printing queue"<<endl;
        for(int i = 0; i< size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Cqueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.print();

    q.pop();
    q.pop();
    q.print();

    q.push(60);
    q.push(70);
    q.push(80);
    q.print();
    return 0;
}