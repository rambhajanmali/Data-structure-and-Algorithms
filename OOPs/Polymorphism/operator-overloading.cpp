#include<iostream>
using namespace std;

class Param{
    public:
    int val;

    void operator+(Param& obj2){
        int value1 = this->val;
        int value2 = obj2.val;
        cout<< (value2-value1) <<endl;
    }
};
int main(){
    Param obj1, obj2;
    obj1.val = 10;
    obj2.val = 20;

    //this should print the difference between them
    obj1+obj2;
    return 0;
}