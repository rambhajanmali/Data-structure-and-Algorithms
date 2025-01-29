#include<iostream>
using namespace std;
int factorial(int n){
    //Base case

    if(n == 1)
    return 1;

    if(n == 0)
    return 1;

    //recursive relation

    int recursionKaAns = factorial(n-1);

    //precessing

       int finalAns = n * recursionKaAns;
       return finalAns;
}
int main(){
    cout<<factorial(5)<<endl;

    return 0;
}