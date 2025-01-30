#include<iostream>
using namespace std;

bool checkSorted(int arr[], int size, int index){
    //base case
    if(index>= size){
        return true;
    }

    //processing
    if(arr[index] > arr[index-1]){
        //aage check karna padega
        // ab recursion shambhal lega
        bool aageKaAns = checkSorted(arr,size,index+1);
        return aageKaAns;
    }
    else{
        //sorted nahi h
        return false;
    }

}
int main(){
    int arr[] = {10,20,5,40,50};
    int size = 5;
    int index = 1;

    bool isSorted = checkSorted(arr,size, index);
    if(isSorted){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
}