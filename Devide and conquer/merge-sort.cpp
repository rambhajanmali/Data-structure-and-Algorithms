#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){

    int mid = (s+e)/2;

    int lenLeft = mid-s+1;
    int lenRight = e-mid;

    //create left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    //copy values from original array to left  array
    int k = s;
    // k => starting index of left array   valurs in original array
    for(int i = 0; i<lenLeft; i++){
        left[i] = arr[k];
        k++;
    }

    //copy values from original array to right  array
    k = mid+1;
    for(int i = 0; i<lenRight; i++){
        right[i] = arr[k];
        k++;
    }


    //actual merge logic here
    //left array is already sorted
    //right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    //yahi pr galti krte h log
    int mainArrayIndex = s;

    while(leftIndex < lenLeft && rightIndex <lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
             mainArrayIndex++;
            leftIndex++;
        }else{
            arr[mainArrayIndex] = right[rightIndex];
              mainArrayIndex++;
            rightIndex++;
        }
      
    }

    // 2 more cases

    //1 case => left array exhaust bur right array me elements abhi bhi bache h
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    //2 case => right array exhaust bur left array me elements abhi bhi bache h
    while(leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    //1 more step pending
    delete [] left;
    delete [] right;
}

void mergeSort(int arr[], int s, int e){
    //base case
    if(s>e){
        //invalid array
        return;
    }
    if(s == e){
        //array has only 1 element
        return;
    }

    //break
    int mid = (s+e)/2;
    // s -> mid => left array
    // mid+1 -> e => right array

    //recursion ko bulao and sort the right and left array
    //recursive call for left array
    mergeSort(arr,s,mid);
    //recursive call for righ array
    mergeSort(arr,mid+1,e);

    //merge two sorted array
    merge(arr,s,e);

}

int main(){
    int arr[] = {5, 4,6,3,7,1};
    int size = 6;
    int s = 0;
    int e = size-1;

    mergeSort(arr,s,e);
    cout<<"after merge sort"<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
