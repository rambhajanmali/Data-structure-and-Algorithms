#include<iostream>
using namespace std;

void findSubSeq(string str, string output , int index){
    //base case
    if(index >= str.length()){
        //ans outpit string me build ho chuka h 
        //print kr do
        cout<<"=> " <<output<<endl;
        return;
    }
    char ch = str[index];

    //exclude
    findSubSeq(str,output,index+1);
    //include
    output.push_back(ch);
    findSubSeq(str,output,index+1);
}
int main(){
string str = "abc";
string output = "";
int index = 0;
findSubSeq(str,output,index);
}