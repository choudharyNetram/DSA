/// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Gap strategy 
// MCM methods 
/// catlan number 


#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 



class Solution {
public:
    int solveRecur(int i, int j, vector<int>&values){
        if(i+1 == j){
            return  0 ; 
        }
       
        int ans = INT_MAX ; 
        for(int k = i+1 ;k<j ; k++){
            ans = min(ans, values[i]*values[j]*values[k] + solveRecur(i,k, values)+solveRecur(k,j,values)) ; 
        }
        return ans ; 
    }


    int solveMemo(int i, int j, vector<int>&values,vector<vector<int>>&dp){
        if(i+1 == j){
            return  0 ; 
        }
         if(dp[i][j] != -1){
            return dp[i][j] ; 
        }
        int ans = INT_MAX ; 
        for(int k = i+1 ;k<j ; k++){
            ans = min(ans, values[i]*values[j]*values[k] + solveMemo(i,k, values, dp)+solveMemo(k,j,values,dp)) ; 
        }
        dp[i][j] = ans ; 

        return ans ; 
    }



    int solveTab(vector<int>&values, int n){
        vector<vector<int>>dp(n, vector<int>(n,0)) ; 
        for(int i = n-1; i>= 0;i--){
            for(int j = i+2; j<n ;j++){
                int ans = INT_MAX ; 
                for(int k = i+1 ;k<j ; k++){
                    ans = min(ans, values[i]*values[j]*values[k] + dp[i][k]+dp[k][j]) ; 
                }
                dp[i][j] = ans ; 
            }
        }
        return dp[0][n-1] ; 
    }

    int minScoreTriangulation(vector<int>& values) {
        int  n = values.size() ; 
       return  solveTab(values, n) ; 
       // vector<vector<int>>dp(n, vector<int>(n,-1)) ; 
       // return solveMemo(0, n-1, values, dp) ; 
    }
};





/* the above question using gap method: 
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int g = 0; g<n; g++){
        for(int i=0, j = g; j<n; i++, j++){
            if(g == 0){
               dp[i][j] = 0;
            }
            else if(g == 1){
               dp[i][j] = 0;
            }
            else if(g == 2){
               dp[i][j] = values[i]*values[j]*values[i+1];
            }
            else{
               int minval = 1e8;
               for(int k = i+1; k<=j-1; k++){
                   int tri = values[i]*values[k]*values[j];
                   int left = dp[i][k];
                   int right = dp[k][j];
                   int total = tri + left + right;
                   minval = min(minval, total);
               }
               dp[i][j] = minval;
            }
        }
    }
    return dp[0][n-1]; 
    }
}; */