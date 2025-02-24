#include<iostream>
#include<queue>
#include<stack>
using namespace std;


void reverseQueue(queue<int> &q){

    stack<int> st;
    //step1: pop all the elements from the queue and push them into the stack
    while(!q.empty()){
        int element = q.front();
        q.pop();

        st.push(element);
    }

    //step 2: pop all the elements from the stack and push them into the queue

    while(!st.empty()){
        int element = st.top();
        st.pop();

        q.push(element);
    }
};


//using recursion

void reverseQueueRecursion(queue<int> &q){
    //base case
    if(q.empty()){
        return;
    }

    //step A
    int temp = q.front();
    q.pop();

    //step B
    reverseQueueRecursion(q);

    // step C
    q.push(temp);
}

 
int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);


    // reverseQueue(q);

    reverseQueueRecursion(q);

    cout<<"After reversing the queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}