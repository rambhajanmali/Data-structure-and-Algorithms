#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};

    //ponter to an array
    int *ptr1 = arr;

    //pointer to an array

    int (*ptr2)[5] = &arr;
    cout<< (*ptr2)[0]<<endl;


    return 0;
}