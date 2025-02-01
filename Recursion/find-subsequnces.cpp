#include<iostream>
#include<vector>
using namespace std;

void findSubSeq(string str, string output , int index, vector<string> &ans){
    //base case
    if(index >= str.length()){
        //ans outpit string me build ho chuka h
        //print kr do
        // cout<<"=> " <<output<<endl;

        ans.push_back(output);
        return;
    }
    char ch = str[index];

    // //exclude
    // findSubSeq(str,output,index+1);
    // //include
    // output.push_back(ch);
    // findSubSeq(str,output,index+1);


    //include
     output.push_back(ch);
    findSubSeq(str,output,index+1, ans);
    //exclude
    output.pop_back();
    findSubSeq(str,output,index+1, ans);
}
int main(){
string str = "abc";
string output = "";
int index = 0;
vector<string> ans;
findSubSeq(str,output,index, ans);

cout<<"printing the subsequences in vector"<<endl;

for(string s: ans){
    cout<<"=>" <<s<<endl;
}
}