#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &st, int element){
    //base case
    if(st.empty() || st.top() < element){
        st.push(element);
        return;
    }
    // 1 case solve karenge
    int temp = st.top();
    st.pop();
    //recursive
    insertSorted(st, element);
    //backtrack
    st.push(temp);
}

void sortStack(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }
    // 1 case
    int temp = st.top();
    st.pop();
    //recursive
    sortStack(st);
    //backtrack
    insertSorted(st, temp);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(5);
    st.push(11);
    st.push(2);
    st.push(13);


    sortStack(st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}