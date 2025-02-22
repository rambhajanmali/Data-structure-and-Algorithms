#include<iostream>
#include<queue>
using namespace std;

int main(){

    // creation
    queue<int> q;

    // insertion

    q.push(10);
    

    //size 

    cout << "size of queue is "<<q.size()<<endl;


    //check empty or not
    if(q.empty() == true){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }

    //remove
    q.pop();

    cout<<"size of queue is "<<q.size()<<endl;


    q.push(20);
    q.push(30);
    q.push(40);

    cout<< "front element of the queue is "<<q.front()<<endl;
    cout<< "last element of the queue is "<<q.back()<<endl;
}