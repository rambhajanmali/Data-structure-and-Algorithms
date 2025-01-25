#include<iostream>
using namespace std;

void solve(int *arr, int size){
    // cout<< "size of an array inside solve function:" <<sizeof(arr)<< endl;
    cout<< "inside solve arr: "<<arr<<endl;
    cout<< "inside solve &arr :"<<&arr<<endl;
}

int main(){

    int arr[] = {10, 20, 30, 40, 50};
    // cout<< "size of an array: " <<sizeof(arr)<<endl;
    solve(arr, 5);

    cout<< "inside main arr: "<<arr<<endl;
    cout<< "inside main &arr :"<<&arr<<endl;

    return 0;
}
