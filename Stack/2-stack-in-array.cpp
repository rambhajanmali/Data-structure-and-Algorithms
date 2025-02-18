#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top1 = -1;   // initially stack is empty
        this->top2 = size; // initially stack is empty
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "satack overflow" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data){
        if(top2-top1 ==1){
            cout<<"stack overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            arr[top1] = 0;
            top1--;
        }
    }
    void pop2(){
        if(top2 == size){
            cout<<"stack underflow"<<endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }

    void print(){
        cout<<endl;
        cout<<"top1 : "<< top1<<endl;
        cout<<"top2 : "<< top2<<endl;
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
Stack st(5);
st.print();


st.push1(12);
st.print();

st.push2(13);
st.print();

st.pop1();
st.print();

    return 0;
}