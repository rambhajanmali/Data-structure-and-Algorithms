#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:

//this function normalises all the words and patterns in the similar format 
// so that we can compare them and find the solution

void createMapping(string& str){
    //find mapping

    char start = 'a';
    char mapping[300] = {0};

    for(auto ch: str){
        if(mapping[ch] == 0){
            mapping[ch] = start;
            start++;
        }
    }
    //update the mapping
    for(int i = 0; i<str.length(); i++){
        char ch = str[i];
        str[i] = mapping[ch];
    }
}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        //firstly normalise the pattern
        createMapping(pattern);

        //sare words ke sath khelna h
        for(string s: words){

            string tempString = s;

            //normalise tempstring
            createMapping(tempString);

            if(tempString == pattern){

                //if mean, that "s" wali string was a valid answer
                ans.push_back(s); 
            }
        }
        return ans;
        
    };
};