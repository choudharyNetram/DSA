// https://leetcode.com/problems/combination-sum-iv/

#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 



class Solution {
public:
    int solveMem(vector<int>& nums,int n,  int target, vector<int>&dp){
        if(target<0){
            return 0 ; 
        }
        if(target==0){
            return 1 ; 
        }
        if(dp[target] != -1){
            return dp[target] ; 
        }
        int count = 0 ; 
        for(int  i = 0 ;i< n; i++){
            count += solveMem(nums, n, target-nums[i], dp) ; 
        }
        dp[target] = count ; 
        return dp[target] ; 
    }

    int solveTabul(vector<int>& nums,int n,  int target){
        vector<unsigned long long>dp(target+1, 0)  ; 
        dp[0] = 1 ; 
        for(int i = 1 ;i<=target ; i++){
            // search in the array 
            for(int j = 0;j<n ;j++){
               if(i-nums[j] >=0){
                   dp[i] += dp[i-nums[j]] ; 
               }
            }
        }
        return dp[target] ; 
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size() ; 
        //vector<int>dp(target+1, -1)  ; 
        return solveTabul(nums, n, target) ; 
    }
};


/* the below solution is using recursion, TLE is coming 
class Solution {
public:
    int solve(vector<int>& nums,int n,  int target){
        if(target<0){
            return 0 ; 
        }
        if(target==0){
            return 1 ; 
        }
        int count = 0 ; 
        for(int  i = 0 ;i< n; i++){
            count += solve(nums, n, target-nums[i]) ; 
        }
        return count ; 
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size() ; 
        return solve(nums, n, target) ; 
    }
};
*/