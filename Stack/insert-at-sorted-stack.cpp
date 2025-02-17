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

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

  int element = 2; // Example element to insert
  insertSorted(st, element);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}