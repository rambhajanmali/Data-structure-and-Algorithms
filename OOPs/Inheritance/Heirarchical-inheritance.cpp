#include<iostream>
using namespace std;

class Car{
    public:
    int price;
    string name;
    int weight;

    void start(){
        cout<<"car is starting"<<endl;
    }
};

class Scorpio : public Car{
   
};
class Fortuner : public Car{
    
};
int main(){
    Scorpio s11;
    s11.start();

    Fortuner f1;
    f1.start();
    return 0;
}