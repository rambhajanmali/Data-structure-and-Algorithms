#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;


//printing of an array
void printArray(int arr[],int size, int index){
    //base case
    if(index >= size){
        return;
    }

    //processing
    cout<<arr[index]<<" ";

    //recursive call 
    printArray(arr,size,index+1);

}


//founding target in an array
  bool searchArray(int arr[], int size, int index , int target){
        //base case

        if(index >= size){
            return false;
        }
        if(arr[index] == target){
            return true;
        }
        //recursive call
        bool smallAns = searchArray(arr,size,index+1,target);
        return smallAns;
    }



//finding minimum number in an array
    void findMini(int arr[], int size , int index, int &mini){
        //bse case
        if(index >= size){
            return;
        }

        //processing
        mini = min(mini, arr[index]);

        //recursive call
        findMini(arr,size,index+1,mini);
    }


//solve() -> store even number in array into a vector
void solve(int arr[], int size, int index, vector<int> &ans){
    //base case
    if(index>= size){
        return;
    }

    //processing
    if(arr[index]%2 == 0){
        ans.push_back(arr[index]);
    }
    //recursive call
    solve(arr,size,index+1,ans);
}



//prinits all the digits of a number
void printDigits(int num){
    //base case
    if(num == 0){
        return;
    }

    //processing
    int digits = num %10;
    //update num
    num = num/10; 

    //recursive call
    printDigits(num);

    //processing
    cout<<digits<<endl;
}


int main(){

int num = 4217;
printDigits(num);

// int arr[] = {11,20,31,40,50};
// int size = 5;
// int index = 0;
//  vector<int> ans;
// solve(arr,size,index,ans);
// //printing the vector
// for(int num: ans){
//     cout<<num<<" ";
// }

// int mini = INT_MAX;
// findMini(arr,size,index,mini);
// cout<<"minimum number is:"<<mini<<endl;


// int target = 60;
// cout<<"target:"<< searchArray(arr,size,index,target)<<endl;
// printArray(arr,size,index);
}