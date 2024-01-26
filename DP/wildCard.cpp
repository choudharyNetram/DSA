////    https://leetcode.com/problems/wildcard-matching/


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    bool solve(string&s , string&p, int i, int j, vector<vector<int>>&dp){
        if(i<0&&j< 0){
            return 1 ; 
        }
        if((i>=0 && j<0)){
            return 0 ; 
        }
        if(i<0 && j>=0 ){
            for(int k = j ; k>=0 ; k--){
                if(p[k] != '*'){
                    return false ; 
                }
            }
            return true ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j] ; 
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = solve(s, p, i-1, j-1, dp) ; 
        }
        else if(p[j] == '*'){
            int emptyStar = solve(s, p, i, j-1,dp) ; 
            //// below replacing * by '*'+s[i]
            int backS = solve(s, p, i-1, j,dp) ; 
            return dp[i][j] = emptyStar||backS ; 
        }
        else {
            return dp[i][j] = false ; 
        }

    }

    bool solve1BasedIndex(string&s , string&p, int i, int j, vector<vector<int>>&dp){
        if(i==0&&j== 0){
            return 1 ; 
        }
        if((i>0 && j<=0)){
            return 0 ; 
        }
        if(i<=0 && j>0 ){
            for(int k = j ; k>=1 ; k--){
                if(p[k-1] != '*'){
                    return false ; 
                }
            }
            return true ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j] ; 
        }
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j] = solve1BasedIndex(s, p, i-1, j-1, dp) ; 
        }
        else if(p[j-1] == '*'){
            int emptyStar = solve1BasedIndex(s, p, i, j-1,dp) ; 
            //// below replacing * by '*'+s[i]
            int backS = solve1BasedIndex(s, p, i-1, j,dp) ; 
            return dp[i][j] = emptyStar||backS ; 
        }
        else {
            return dp[i][j] = false ; 
        }

    }


    bool solveTab(string s, string p){
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, 0));         
        dp[0][0] = 1 ; 
        for(int j =1 ; j<=p.size() ; j++){
            bool flag = 1 ; 
            for(int k = j ; k>=1 ; k--){
                if(p[k-1] != '*'){
                    flag = false ; 
                    break ; 
                }
            }
            if(flag){
                dp[0][j] = 1 ; 
            }
        }
        for(int i = 1 ; i<=s.length();i++ ){
            for(int j = 1 ;j<=p.length(); j++){
                 if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1] ; 
                }
                else if(p[j-1] == '*'){
                    int emptyStar = dp[i][j-1] ; 
                    //// below replacing * by '*'+s[i]
                    int backS = dp[i-1][j] ; 
                    dp[i][j] = emptyStar||backS ; 
                }
                else {
                     dp[i][j] = false ; 
                }
            }
        }
        return dp[s.length()][p.length()] ; 
    }

    bool spaceOpt(string s, string p){
        vector<int>prev(p.length()+1, 0) ; 
        vector<int>curr(p.length()+1, 0) ; 
        prev[0] = 1 ; 
        for(int j =1 ; j<=p.size() ; j++){
            bool flag = 1 ; 
            for(int k = j ; k>=1 ; k--){
                if(p[k-1] != '*'){
                    flag = false ; 
                    break ; 
                }
            }
            prev[j] = flag ; 
        
        }
        for(int i = 1 ; i<=s.length();i++ ){
            for(int j = 1 ;j<=p.length(); j++){
                 if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j] = prev[j-1] ; 
                }
                else if(p[j-1] == '*'){
                    int emptyStar = curr[j-1] ; 
                    //// below replacing * by '*'+s[i]
                    int backS = prev[j] ; 
                    curr[j] = emptyStar||backS ; 
                }
                else {
                     curr[j] = false ; 
                }
            }
            prev = curr ;  
        }
        return prev[p.length()] ; 
    }

    bool isMatch(string s, string p) {
        return spaceOpt(s, p) ; 
        //return solveTab(s,p) ; 
        //vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1))  ; 
      //  return solve1BasedIndex(s, p, s.size(), p.size(), dp) ; 
    }
};