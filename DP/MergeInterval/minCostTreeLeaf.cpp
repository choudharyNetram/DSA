/// Minimum Cost Tree From Leaf Values
///    https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/



#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include<map>  
using namespace std;

class Solution {
public:
    /// for loop 1,2,3,4, n-1 ; 
    // start from i+1, to j-1  ; 
    int recur(vector<int>&arr, map<pair<int,int>, int>&maxi , int left,  int right,  vector<vector<int>>&dp){
        if(left==right){
            return 0; 
        }
        if(dp[left][right] != -1){
            return dp[left][right] ; 
        }
        int ans = INT_MAX ; 
        for(int k = left ; k<right;  k++){
            ans = min(ans, maxi[{left,k}]*maxi[{k+1, right}] + recur(arr, maxi, left, k, dp)+recur(arr, maxi,k+1, right, dp)) ; 
        }
        return dp[left][right] =  ans ; 
    }

    int solveTab(vector<int>& arr, map<pair<int,int>, int>&maxi ){
        int n = arr.size() ; 
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)) ; 
        for(int left = n-1; left>=0; left--){
            for(int right = left+1  ; right<n ; right++){
                int ans = INT_MAX ; 
                for(int k = left ; k<right;  k++){
                ans = min(ans, maxi[{left,k}]*maxi[{k+1, right}] + dp[left][k]+dp[k+1][right]) ; 
                }
                dp[left][right] =  ans ; 
            }
        } 
        return dp[0][n-1] ; 
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int>maxi    ;
        int n =  arr.size() ;  
        for(int i = 0 ;  i<n ; i++){
            maxi[{i,i}] = arr[i] ; 
            for(int j = i+1 ; j<n ;j++){
                maxi[{i, j}] = max(maxi[{i,j-1}], arr[j]) ; 
            }
        }
        return solveTab(arr, maxi) ; 
        /*
        vector<vector<int>>dp(n, vector<int>(n, -1)) ; 
        return recur(arr, maxi, 0, n-1, dp) ; */
    }
};