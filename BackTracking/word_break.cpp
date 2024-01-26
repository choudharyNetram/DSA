//// https://leetcode.com/problems/word-break-ii/

#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
class Solution {
public:
    void backtrack(unordered_map<string, bool> &diction ,int index,int N,string fullstr,  vector<string> &ans ,string currs,  string s){
        if(index>N){
            return ; 
        }
        if(index == N){
            if(diction[currs]){
                string t  ; 
                if(fullstr.empty()){
                    t = currs ; 
                }
                else {
                   t = fullstr+" "+currs ; 
                }
                
                ans.push_back(t) ;
                return ; 
            }
        }
        // 

        // two conditions of going ahead, we got the currs in our map, and second is we would get more 
        //  spelling by adding next char 
        if(diction[currs  + s[index]]){
            //currs.push_back(s[index]) ; 
             string temp ; 
            if(!fullstr.empty()){
                temp =  fullstr+" " + currs+s[index] ; 
            }
            else {
                temp = currs+s[index]  ; 
            }
           
            backtrack(diction, index+1, N, temp, ans, "", s) ; 
        }
        backtrack(diction, index+1, N, fullstr, ans, currs+s[index], s) ; 
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> diction ; 
        int n = wordDict.size() ; 
        for(int i = 0 ;i < n ;i++){
            diction[wordDict[i]] = 1 ; 
        }
        vector<string> ans ; 
        int N = s.length() ; 
        string currs = "" ; 
        string fullstr = "" ; 
        backtrack(diction, 0,N,fullstr,  ans, currs, s) ; 
        return ans  ; 
    }
};