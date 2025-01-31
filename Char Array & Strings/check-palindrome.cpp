#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char ch[], int n){
 // n length of string
 int i = 0;
 int j = n-1;

 while(i<=j){
  if(ch[i] == ch[j]){
    i++;
    j--;
  }
  else{
    return false;
  }
 }
 return true;
}
int main() {
   char ch[100];
   cin.getline(ch, 100);
    int len = strlen(ch);
   bool isPalindrome = checkPalindrome(ch,len);
   if(isPalindrome ){
    cout<<"valid palindrome"<<endl;
   }
   else{
    cout<<"invalid palindrome"<<endl;
   }
  
    return 0;
}