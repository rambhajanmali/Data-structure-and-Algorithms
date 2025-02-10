#include<iostream>
using namespace std;


class Animal{
    public:
    virtual void speak(){
        cout<<"animal is speaking"<<endl;
    }
};

class Dog : public Animal{
    public:
    //method overriding
    void speak(){
        cout<<"dog is barking"<<endl;
    }
};
int main(){
    // Dog d1;
    // d1.speak();

       // Animal *a = new Animal();
       // a->speak();

       // Dog *a = new Dog();
       // a->speak();

      //    Upcasting
           Animal *a = new Dog();
              a->speak();
         
        //Downcasting
        Dog *d = (Dog*) new Animal();
        d->speak();      

    return 0;
}