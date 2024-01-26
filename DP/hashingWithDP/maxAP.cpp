///    https://leetcode.com/problems/longest-arithmetic-subsequence/description/



#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countBackward(vector<int>&nums, int diff, int idx){
        if(idx<0){
            return 0 ; 
        }
        // go back form the index idx 
        int ans = 0; 
        for(int k = idx -1 ; k>=0 ;k--){
            if(diff == nums[idx]-nums[k]){
                ans = max(ans, 1+countBackward(nums, diff, k)) ; 
            }
        }
        return ans; 
    }

    int countBackwardDP(vector<int>&nums, int diff, int idx,unordered_map<int,int>dp[]){
        if(idx<0){
            return 0 ; 
        }
        if(dp[idx].count(diff)){
            return dp[idx][diff] ; 
        }
        // go back form the index idx 
        int ans = 0; 
        for(int k = idx -1 ; k>=0 ;k--){
            if(diff == nums[idx]-nums[k]){
                ans = max(ans, 1+countBackwardDP(nums, diff, k, dp)) ; 
            }
        }
        return dp[idx][diff] = ans; 
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() ; 
        if(n<=2){
            return n ; 
        }
        int ans  = 0 ; 
        unordered_map<int, int>dp[n+1] ; 
        for(int i = 1; i<n ; i++){
            for(int j = 0 ;j<i ;j++){
                int diff = nums[i]-nums[j] ; 
                int cnt = 1  ; 
                if(dp[j].count(diff)){
                    cnt = dp[j][diff] ; 
                }
                dp[i][diff] = 1+cnt ; 
                ans = max(ans, dp[i][diff]) ; 
            }
        }
        return ans ; 

        
        
        /*
        unordered_map<int,int>dp[n+1] ; 
        for(int i = 0 ; i<n-1 ;i++){
            for(int j = i+1;j<n ;j++){
                ans = max(ans, 2+countBackwardDP(nums,nums[j]-nums[i], i, dp)) ; 
            }
        }
        return ans ;
*/
        /*
        for(int i = 0 ; i<n-1 ;i++){
            for(int j = i+1;j<n ;j++){
                ans = max(ans, 2+countBackward(nums,nums[j]-nums[i], i)) ; 
            }
        }
        return ans ; */
    
       
    }
};