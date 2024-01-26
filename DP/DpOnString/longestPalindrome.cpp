/// https://leetcode.com/problems/longest-palindromic-subsequence/




#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int solve(string &s , int n, int i , int j){
        if(i>j){
            return 0 ; 
        }
        if(i==j){
            return 1 ; 
        }
        int ans = 0 ; 
        if(s[i]==s[j]){
            ans  = 2+solve(s, n, i+1, j-1) ; 
        }
        else {
            ans = max(solve(s, n, i+1, j), solve(s, n, i,j-1)); 
        }
        return ans ; 
    }

    int solveMemo(string &s , int n, int i , int j, vector<vector<int>>&dp){
        if(i>j){
            return 0 ; 
        }
        if(i==j){
            return 1 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]  ; 
        }
        int ans = 0 ; 
        if(s[i]==s[j]){
            ans  = 2+solveMemo(s, n, i+1, j-1,dp) ; 
        }
        else {
            ans = max(solveMemo(s, n, i+1, j,dp), solveMemo(s, n, i,j-1,dp)); 
        }
        return dp[i][j] = ans ; 
    }

    int solveTab(string&s){
        int n = s.length() ; 
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)) ; 
        for(int i = n-1 ; i>= 0 ; i--){
            for(int j = i;  j<n ;j++){
                int ans = 0 ; 
                if(i==j){
                    dp[i][j] = 1 ; 
                }
                else {
                     if(s[i]==s[j]){
                        ans  = 2+dp[i+1][j-1] ; 
                    }
                    else {
                        ans = max(dp[i+1][j], dp[i][j-1]); 
                    }
                    dp[i][j] = ans ; 
                }
               
            }
        }
        return dp[0][n-1] ; 
    }

    int spaceOpt(string s){
        int n = s.length() ; 
        vector<int>curr(n+1, 0) ; 
        vector<int>next(n+1, 0) ; 
        for(int i = n-1 ; i>= 0 ; i--){
            for(int j = i;  j<n ;j++){
                int ans = 0 ; 
                if(i==j){
                    curr[j] = 1 ; 
                }
                else {
                     if(s[i]==s[j]){
                        ans  = 2+next[j-1] ; 
                    }
                    else {
                        ans = max(next[j], curr[j-1]); 
                    }
                    curr[j] = ans ; 
                }
               
            }
            next = curr ; 
        }
        return curr[n-1] ; 
    }
    int longestPalindromeSubseq(string s) {
        return spaceOpt(s) ; 
        /*int n = s.length() ; 
        vector<vector<int>>dp(n, vector<int>(n, -1)) ; 
        return solveMemo(s, n, 0, n-1, dp)  ; */
       // return solve(s,  n, 0, n-1) ; 
    }
};