#include<iostream>
#include<queue>
using namespace std;

void interLeaveQueue(queue<int> & q){
   //tep A setrate both halves
int n = q.size();
if(q.empty()){
    return;
};

int k = n/2;
int count = 0;
queue<int> q2;

while(!q.empty()){
    int temp = q.front();
    q.pop();
    q2.push(temp);
    count++;
    if(count == k){
        break;
    }
}

//interleave start kerdo

while(!q.empty() && !q2.empty()){
    int first = q2.front();
    q2.pop();
    q.push(first);

   int second = q.front();
    q.pop();
    q.push(second);
}
//odd wala case

if(n & 1){
    int temp = q.front();
    q.pop();
    q.push(temp);
}
};


int main(){
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
q.push(6);
q.push(7);

interLeaveQueue(q);

while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}

return 0;
}