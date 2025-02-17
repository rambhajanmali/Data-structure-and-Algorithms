#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int & pos, int &ans){
    //base case
    if(pos == 1){
        ans = st.top(); //for meddile element print case
        // st.pop();  //for middle element delete case
        return;
    }
    //1 case ham solve karenge
    pos--;
    int temp = st.top();
    st.pop();

    //recursive 
    solve(st, pos, ans);

    //backtrak
    st.push(temp);
}

int getMiddleElement(stack<int> &st){
    int size = st.size();
    if(st.empty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else{
        //stack is not empty
        //odd
        int pos = 0;
        if(size & 1){
            pos = size/2 +1;
        }
        else{
            //even
            pos = size/2;
        }
        int ans = -1;
        solve(st, pos, ans);
        return ans;
    }
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int mid = getMiddleElement(st);
    cout<<"Middle element of the stack is: "<<mid<<endl;
}