#include <iostream>
using namespace std;

int createNum(int numOfDigit){
  int num = 0;
  for(int i=0; i<= numOfDigit; i++){

cout<<"enter digit"<<endl;
    int digit;
    cin>>digit;
    num = num*10 + digit;
    cout<<"number created so far:"<<num<<endl;
  }
  return num;
}

int main() {
int numOfDigit;
cin>>numOfDigit;
int finaAns =  createNum(numOfDigit);
cout<<finaAns<<endl;

  return 0;
}