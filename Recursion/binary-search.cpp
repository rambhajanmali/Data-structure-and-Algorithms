#include<iostream>
using namespace std;

int binSearch(int arr[], int s, int e, int target){
    //base case
    if(s>e){
        //element not found
        return -1;
    }
    //processing -> 1 case solve karna padega
    int mid = s + (e-s)/2;
    if(arr[mid] == target){
        return mid;
    }

    //baki recursion shambhal lega
    if(arr[mid] > target){
        //left side
        return binSearch(arr,s,mid-1,target);
    }
    else{
        //right side
        return binSearch(arr,mid+1,e,target);
    }
}
int main(){
int arr[] = {1,2,3,4,5,6,7,8,9,10};
int start = 0;
int size = 10;
int end = size-1;
int target = 5;

int foundIndex = binSearch(arr,start,end,target);
if(foundIndex == -1){
    cout<<"Element not found"<<endl;
}
else{
    cout<<"Element found at index: "<<foundIndex<<endl;
}
}