#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    int weight;


    void eat()
    {
        cout << "animal is eating" << endl;
    }
};

class Dog : private Animal{
    public:
    void print(){
        cout <<this->age << endl;
    }
};


int main()
{
    Dog d1;
    d1.print();
   
    return 0;
}
