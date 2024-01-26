



/// https://leetcode.com/problems/longest-common-subsequence/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:

    int recur(string &a, string &b, int i , int j,  vector<vector<int>>&dp){
        if(i==a.length()){
            return 0 ; 
        }
        if(j==b.length()){
            return 0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j] ; 
        }
        int ans = 0 ; 
        if(a[i]==b[j]){
            ans = recur(a, b, i+1, j+1,dp)+1 ; 
        }
        else {
            ans = max(recur(a,b,i+1, j,dp), recur(a,b,i, j+1,dp)) ; 
        }
        return dp[i][j] = ans ; 
    }

    int solveTab(string a, string b){
        int m = a.length() ; 
        int n = b.length()  ; 
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0)) ; 
        for(int i = m-1 ; i>= 0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                int ans = 0 ; 
                if(a[i]==b[j]){
                    ans = dp[i+1][j+1] +1 ; 
                }
                else {
                    ans = max(dp[i+1][j],dp[i][j+1]) ; 
                }
                 dp[i][j] = ans ; 
            }
        }
        return dp[0][0] ; 
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTab(text1, text2) ; 

        /*
        int m = text1.length() ; 
        int  n = text2.length() ; 
        vector<vector<int>>dp(m, vector<int>(n,-1)) ; 
        return recur(text1, text2, 0, 0, dp) ;
       */
       
        /* 
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> matrix(m, vector<int>(n));
        for(int i = 0  ;i<m ;i++){
            for(int j = 0 ;j<n ;j++){
                
                if(i == 0 ){
                    if(j==0){
                        if(text1[i]==text2[j]){
                            matrix[i][j] = 1 ; 
                        }
                        else {
                            matrix[i][j] = 0 ; 
                        }
                    }
                    else {
                         if(text1[i]==text2[j]){
                            matrix[i][j] = 1  ; 
                        }
                        else {
                            matrix[i][j] = matrix[i][j-1] ; 
                        }
                    }
                }
                else if(j==0){
                    if(i==0){
                        if(text1[i]==text2[j]){
                            matrix[i][j] = 1 ; 
                        }
                        else {
                            matrix[i][j] = 0 ; 
                        }
                    }
                    else {
                         if(text1[i]==text2[j]){
                            matrix[i][j] = 1  ; 
                        }
                        else {
                            matrix[i][j] = matrix[i-1][j] ; 
                        }
                    }
                }
                else{
                    if(text1[i]==text2[j]){
                        matrix[i][j] = matrix[i-1][j-1]+1; 
                    }
                    else {
                        matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]) ;
                    }
                    
                   
                }
            }
        }
        return matrix[m-1][n-1] ;*/

    }
};