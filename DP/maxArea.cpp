/// https://leetcode.com/problems/maximal-square/description/


#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 
class Solution {
public:
    int solveRecur(vector<vector<char>> mat , int i, int j ,int m ,int n, int &maxi){
        if(i>=m || j>=n){
            return 0 ; 
        }
        int right = solveRecur(mat, i, j+1,m,n,  maxi) ; 
        int diagonal  = solveRecur(mat, i+1, j+1,m,n, maxi) ; 
        int down = solveRecur(mat,  i+1, j,m,n, maxi) ; 
        if(mat[i][j] == '1'){
            int ans = 1+min(diagonal, min(right, down)) ; 
            maxi = max(maxi, ans) ; 
            return ans  ; 
        }
        else {
            return 0 ; 
        }
    }

     int solveMemo(vector<vector<char>> &mat , int i, int j ,int m ,int n, int &maxi, vector<vector<int>>&dp){
        if(i>=m || j>=n){
            return 0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        int right = solveMemo(mat, i, j+1,m,n,  maxi, dp) ; 
        int diagonal  = solveMemo(mat, i+1, j+1,m,n, maxi,  dp) ; 
        int down = solveMemo(mat,  i+1, j,m,n, maxi, dp) ; 

        if(mat[i][j] == '1'){
            dp[i][j] = 1+min(diagonal, min(right, down)) ; 
            maxi = max(maxi, dp[i][j]) ;
            return dp[i][j]  ; 
        }
        else {
            return 0 ; 
        }
    }
    int solveTab(vector<vector<char>> &mat, int &maxi){
        int row = mat.size() ; 
        int col = mat[0].size() ; 
        vector<vector<int>>dp(row+1, vector<int>(col+1, 0)) ; 
        
        for(int i =row-1 ; i>= 0;i--){
            for(int j = col-1 ;j>= 0 ;j--){
                int right = dp[i][j+1] ; 
                int diagonal  = dp[i+1][j+1] ; 
                int down = dp[i+1][j] ; 
        
                if(mat[i][j] == '1'){
                    dp[i][j] = 1+min(diagonal, min(right, down)) ; 
                    maxi = max(maxi, dp[i][j]) ;
                }
                else {
                    
                }
            }        
        }
        return dp[0][0] ; 
        
    }

    int solveSpaceOpt(vector<vector<char>> &mat, int &maxi){
        int row = mat.size() ; 
        int col = mat[0].size() ; 
        vector<int>curr(col+1, 0) ;
        vector<int>next(col+1, 0) ; 
        for(int i =row-1 ; i>= 0;i--){
            for(int j = col-1 ;j>= 0 ;j--){
                int right = curr[j+1] ; 
                int diagonal  = next[j+1] ; 
                int down =  next[j]; 
        
                if(mat[i][j] == '1'){
                    curr[j] = 1+min(diagonal, min(right, down)) ; 
                    maxi = max(maxi,curr[j]) ;
                }
                else {
                    curr[j] = 0 ; 
                }
            }  
            next = curr ; 
     
        }
        return next[0] ; 
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0 ; 
       // solveRecur(mat, 0, 0 , m, n, maxi) ; 
      // int m = matrix.size() ; 
       //int n = matrix[0].size() ; 
        //vector<vector<int> > dp(m, vector<int>(n, -1))  ; 
        //solveMemo(matrix, 0, 0 , m ,n , maxi, dp) ; 
        solveSpaceOpt(matrix, maxi) ; 
        return maxi*maxi ; 
    }
};