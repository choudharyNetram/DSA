/// https://leetcode.com/problems/pizza-with-3n-slices/


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int solve(int index, int endIndex, vector<int>&slices , int n){
        if(n==0 || index> endIndex){
            return 0 ; 
        }
        int takeIdx = slices[index]+solve(index+2, endIndex, slices, n-1) ; 
        int notTake = solve(index+1,endIndex, slices, n) ; 
        return max(takeIdx, notTake) ; 
    }

    int RecMemo(int index, int endIndex, vector<int>&slices , int n, vector<vector<int>>&dp){
        if(n==0 || index> endIndex){
            return 0 ; 
        }
        if(dp[index][n] != -1){
            return dp[index][n] ; 
        }
        int takeIdx = slices[index]+RecMemo(index+2, endIndex, slices, n-1, dp) ; 
        int notTake = RecMemo(index+1,endIndex, slices, n,dp) ; 
        return dp[index][n]= max(takeIdx, notTake) ; 
    }

    int bottomUp(vector<int>&slices){
        int k = slices.size() ; 
        vector<vector<int>>dp1(k+2, vector<int>(k+2, 0)) ; 
        vector<vector<int>>dp2(k+2, vector<int>(k+2, 0)) ; 
        for(int  index  = k-2 ; index>= 0 ; index--){
            for(int n = 1 ; n<=k/3 ; n++){
                int takeIdx = slices[index]+ dp1[index+2][n-1] ; 
                int notTake = dp1[index+1][n] ; 
                dp1[index][n]= max(takeIdx, notTake) ; 
            }
        }

        for(int  index  = k-1 ; index>= 1; index--){
            for(int n = 1 ; n<=k/3 ; n++){
                int takeIdx = slices[index]+ dp2[index+2][n-1] ; 
                int notTake = dp2[index+1][n] ; 
                dp2[index][n]= max(takeIdx, notTake) ; 
            }
        }
        return max(dp1[0][k/3], dp2[1][k/3]) ; 

    }

    int spaceOpt(vector<int>& slices){
        int k = slices.size() ; 
        vector<int> prev1(k+2, 0)  ; 
        vector<int> curr1(k+2, 0)  ; 
        vector<int> next1(k+2, 0)  ; 
        for(int  index  = k-2 ; index>= 0 ; index--){
            for(int n = 1 ; n<=k/3 ; n++){
                int takeIdx = slices[index]+ next1[n-1] ; 
                int notTake = curr1[n] ; 
                prev1[n]= max(takeIdx, notTake) ; 
            }
            next1 = curr1 ; 
            curr1 = prev1 ; 
        }
        vector<int> prev2(k+2, 0)  ; 
        vector<int> curr2(k+2, 0)  ; 
        vector<int> next2(k+2, 0)  ; 
        for(int  index  = k-1 ; index>= 1; index--){
            for(int n = 1 ; n<=k/3 ; n++){
                int takeIdx = slices[index]+ next2[n-1] ; 
                int notTake = curr2[n] ; 
                prev2[n]= max(takeIdx, notTake) ; 
            }
            next2 = curr2  ; 
            curr2 = prev2 ; 
        }
        return max(curr1[k/3], curr2[k/3]) ; 

    }
    int maxSizeSlices(vector<int>& slices) {
        // this is the same kind question like house robbery(adajacent neightbour)
        int k = slices.size() ; 
        int  n = k/3 ; 
        return spaceOpt(slices) ; 
       // return bottomUp(slices) ; 
        /*
        vector<vector<int>>dp1(k, vector<int>(k, -1)) ; 
        int case1 = RecMemo(0,k-2, slices, n, dp1) ; 
        vector<vector<int>>dp2(k, vector<int>(k, -1)) ; 

        int case2 = RecMemo(1, k-1, slices, n, dp2) ; 
        return max(case1, case2) ; */
       // int case1 = solve(0,k-2,  slices, k/3) ; 
        //int case2 = solve(1,k-1 ,  slices, k/3) ; 
       // return max(case1, case2) ; 
    }
};