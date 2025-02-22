#include<iostream>
#include<queue>
using namespace std;

int main(){

    deque<int> q;
    q.push_back(10);
    q.push_front(20);

    // q.pop_back();
    q.pop_front();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    cout<<q.size()<<endl;

    return 0;
}