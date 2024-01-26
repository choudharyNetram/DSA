/// https://leetcode.com/problems/partition-equal-subset-sum/f 


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool solve(vector<int>&nums, int index, int n, int sum, int halfSum ){
        if(index>=n){
            return false  ; 
        }
        if(sum == halfSum ){
            return true ; 
        }
        if(sum>halfSum){
            return false ; 
        }
        // include the current element 
        bool include = solve(nums,  index+1, n, sum+nums[index], halfSum) ; 
        bool exclude = solve(nums, index+1, n , sum,halfSum) ; 

        return (include||exclude) ; 
        
    }
    bool solveMemo(vector<int>&nums, int index, int n, int sum, int halfSum ,vector<vector<int>>&dp ){
        if(index>=n){
            return false  ; 
        }
        if(sum == halfSum ){
            return true ; 
        }
        if(sum>halfSum){
            return false ; 
        }
        if(dp[index][sum] != -1){
            return dp[index][sum] ; 
        }
        // include the current element 
        bool include = solveMemo(nums,  index+1, n, sum+nums[index], halfSum,dp) ; 
        bool exclude = solveMemo(nums, index+1, n , sum,halfSum,dp) ; 

        return dp[index][sum] = (include||exclude) ; 
        
    }


    bool solveTab(vector<int>&nums, int halfSum, int n){
        vector<vector<bool>>dp(n+1, vector<bool>(halfSum+1, false)) ; 
        // what is the relation dp[i][target] = dp[i][target]|| dp[i][target-nums[i]]
        for(int i = 0 ;i<=n ;i++){
            dp[i][0] = true ; 
        }
        for(int i = n-1 ;i >=0;i--){
            for(int target =  1; target <= halfSum; target++){
                if(target-nums[i]>= 0){
                    dp[i][target] = dp[i+1][target] || dp[i+1][target-nums[i]] ; 
                }
                else {
                    dp[i][target] = dp[i+1][target] ; 
                }
                
            }
        }
        
        return dp[0][halfSum]  ; 
    }

    bool spaceOpt(vector<int>&nums, int halfSum, int n){
        vector<int>curr(halfSum+1, 0) ; 
        vector<int>next(halfSum+1, 0) ; 
        next[0] = 1 ; curr[0] = 1 ;

        for(int i = n-1 ;i >=0;i--){
            for(int target =  1; target <= halfSum; target++){
                if(target-nums[i]>= 0){
                    curr[target] = next[target] || next[target-nums[i]] ; 
                }
                else {
                    curr[target] = next[target] ; 
                }
                
            }
            next = curr ; 
        }
        
        return curr[halfSum]  ; 
    } 
    bool bottomUp(vector<int>&nums, int halfSum, int n){
        vector<vector<bool>>dp(n+1, vector<bool>(halfSum+1, false)) ; 
        for(int i = 0 ;i<=n ;i++){
            dp[i][0] = true ; 
        }
        for(int i = 1 ;i <=n ;i++){
            for(int target =  1; target <= halfSum; target++){
                if(target-nums[i-1]>= 0){
                    dp[i][target] = dp[i-1][target] || dp[i-1][target-nums[i-1]] ; 
                }
                else {
                    dp[i][target] = dp[i-1][target] ; 
                }
                
            }
        }
        
        return dp[n][halfSum]  ; 
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        if (totalSum % 2 != 0) {
            return false;
        }
        int halfSum = totalSum/2 ; 
        return spaceOpt(nums, halfSum, n) ; 
        //vector<vector<int>>dp(n, vector<int>(halfSum+1, -1)) ; 
       // return solveMemo(nums,  0, n, 0, halfSum, dp) ; 
    }
};



/*  the below solution is dp based 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // If the total sum is odd, equal partition is not possible
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int targetSum = totalSum / 2;
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true; // Base case: subset with sum 0 is always possible
        
        for (int num : nums) {
            for (int i = targetSum; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[targetSum];
    }
};
*/
