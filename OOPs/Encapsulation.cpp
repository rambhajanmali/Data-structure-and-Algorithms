#include <iostream>
using namespace std;

class Animal
{
private:
    int age;
    int weight;

public:
    void eat()
    {
        cout << "animal is eating" << endl;
    }
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
};

int main()
{
    return 0;
}