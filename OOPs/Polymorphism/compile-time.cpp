#include<iostream>
using namespace std;

//function overloading
class Maths{
    public:

    int sum(int a, int b){
        cout<<"I am in first signature"<<endl;
        return a+b;
    }

    int sum(int a, int b, int c){
        cout<<"I am in second signature"<<endl;
        return a+b+c;
    }

    int sum(int a, float b){
        cout<<"I am in third signature"<<endl;
        return a+b+10;
    }
};

int main(){
  Maths obj;
  cout<<obj.sum(10, 5.13f)<<endl;
    return 0;
}