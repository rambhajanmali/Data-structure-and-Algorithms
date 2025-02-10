#include<iostream>
using namespace std;

class Animal{
//state or properties
private:
int weight;

public:
int age;
string type;

//default constructor
Animal(){
    this->weight = 0;
    this->age = 0;
    this->type = "";
    cout << "constructor called" << endl;
}

//parameterized constructor
Animal(int age){
    this->age = age;
    cout << "parameterized constructor called" << endl;
}

Animal(int age, int weight){
    this->age = age;
    this->weight = weight;
    cout << "parameterized constructor 2 called" << endl;
}

//copy constructor
Animal(Animal &obj){
    this->age = obj.age;
    this->weight = obj.weight;
    this->type = obj.type;
    cout << "copy constructor called" << endl;
}

//behaviour or methods or functions

void eat(){
cout << "animal is eating" << endl;
}

//getter and setter
int getWeight(){
    return weight;
};
void setWeight(int weight){
  this->weight = weight;
}

//destructor
~Animal(){
    cout<<"I am inside destructor"<<endl;
}
};  

int main(){
//object creation

//static
// Animal ramesh;
// ramesh.age = 10;
// ramesh.type = "lion";
// cout <<"age of ramesh is :"<< ramesh.age<<endl;
// cout << " type  of ramesh is :" << ramesh.type << endl;

// // to access private members we use getter and setter
// ramesh.setWeight(100);
// cout << "weight of ramesh is :" << ramesh.getWeight() << endl;



// //dynamic memory allocation
// Animal * suresh = new Animal();
// (*suresh).age = 20;
// (*suresh).type = "tiger";

// //alternate - dynamic memory allocation
// suresh->age = 20;
// suresh->type = "tiger";
// suresh->eat();


Animal a(10);
Animal* b = new Animal(20,19);

//object copy
Animal c = a;   
Animal d(a);

Animal a;
a.age = 3;
}