#include<iostream>
using namespace std;

class Fruit{
    public:
    string name;
};

class Mango : public Fruit{
    public:
    int weight;
};

class Alphonso : public Mango{
    public:
    int sugerlevel;
};

int main(){
    Alphonso a;
    cout<<  a.name<<" "<<a.weight<<" "<<a.sugerlevel<<endl;
        return 0;
}