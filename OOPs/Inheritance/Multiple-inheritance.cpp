#include<iostream>
using namespace std;

// class A{
//     public:
//     int physics;
// };
// class B{
//     public:
//     int chemistry;
// };

// class C : public A, public B{
//     public:
//     int maths;
// };

// int main(){
//     C obj;
//     cout<<obj.physics<<" "<<obj.chemistry<<" "<<obj.maths<<endl;
//     return 0;
// }



//when both parent class have same value
class A{
    public:
    int physics;
};
class B{
    public:
    int physics;
    B(){
        physics = 10;
    }
};

class C : public A, public B{
    public:
    int maths;
};

int main(){
    C obj;
    cout<<obj.B::physics<<" "<<obj.maths<<endl;  //use scope resolution operator to access the value of physics from class B
    return 0;
}