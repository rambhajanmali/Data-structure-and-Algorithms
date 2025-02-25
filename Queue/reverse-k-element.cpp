#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseK(queue<int> &q, int k){
    // step A queue -> K element -> stack

    stack<int> st;
    int count = 0;
    int n = q.size();

    if( k < 0 || k > n){
        return;
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        st.push(temp);
        count++;

        if( count == k){
            break;
        }
    }


    // step B stack -> queue me wapas
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }

    //step C push n-k elements from  front to back

    count = 0;
    while(!q.empty() && n-k != 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
        if(count == n-k){
            break;
        }
       
    }
    
};

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseK(q, 3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}