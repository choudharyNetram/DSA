/// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

// 

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

     int recurMy(int idx, vector<int>& nums1, vector<int>& nums2,  int n){
        if(idx==n){ 
            return 0 ; 
        }
        int prev1 = nums1[idx-1] ; 
        int prev2 = nums2[idx-1] ;
        int ans = INT_MAX ; 
        if(nums1[idx]>prev1 && nums2[idx]>prev2 ){
           ans =  recurMy(idx+1, nums1, nums2,n ) ; 
        }
        if(nums1[idx]>prev2 && nums2[idx]>prev1) {
            int curr1 = nums1[idx] ; int curr2 = nums2[idx] ; 
            // swapping the elements 
            nums1[idx] = curr2 ; nums2[idx] = curr1 ; 
            ans = min(ans, 1+recurMy(idx+1, nums1, nums2, n) ) ; 
            nums1[idx] = curr1 ; nums2[idx] = curr2 ; 
        }
        return ans ; 
    }
    int recur(int idx, vector<int>& nums1, vector<int>& nums2,bool isPrevSwapped,  int n){
        if(idx==n){ 
            return 0 ; 
        }
        int prev1 = nums1[idx-1] ; 
        int prev2 = nums2[idx-1] ; 
        if(isPrevSwapped){
            swap(prev1, prev2) ; 
        }
        int ans = INT_MAX ; 
        if(nums1[idx]>prev1 && nums2[idx]>prev2 ){
           ans =  recur (idx+1, nums1, nums2,0,n ) ; 
        }
        if(nums1[idx]>prev2 && nums2[idx]>prev1) {
            ans = min(ans, 1+recur(idx+1, nums1, nums2,1 , n) ) ; 
        }
        return ans ; 
    }

    int recurMemo(int idx, vector<int>& nums1, vector<int>& nums2,bool isPrevSwapped,  int n, vector<vector<int>>&dp){
        if(idx==n){ 
            return 0 ; 
        }
        int prev1 = nums1[idx-1] ; 
        int prev2 = nums2[idx-1] ; 
        if(dp[idx][isPrevSwapped] != -1){
            return dp[idx][isPrevSwapped] ; 
        }
        if(isPrevSwapped){
            swap(prev1, prev2) ; 
        }
        int ans = INT_MAX ; 
        if(nums1[idx]>prev1 && nums2[idx]>prev2 ){
           ans =  recurMemo(idx+1, nums1, nums2,0,n,dp ) ; 
        }
        if(nums1[idx]>prev2 && nums2[idx]>prev1) {
            ans = min(ans, 1+recurMemo(idx+1, nums1, nums2,1 , n,dp) ) ; 
        }
        return dp[idx][isPrevSwapped] = ans ; 
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int  n = nums1.size() ; 
        vector<vector<int>>dp(n+1, vector<int>(2, 0)) ; 
        for(int idx = n-1 ; idx>= 1 ; idx--){
            for(int swapped = 1  ; swapped>= 0 ;swapped--){
                int prev1 = nums1[idx-1] ; 
                int prev2 = nums2[idx-1] ; 
                if(swapped){
                    swap(prev1, prev2) ; 
                }
                int ans = INT_MAX ; 
                if(nums1[idx]>prev1 && nums2[idx]>prev2 ){
                    ans = dp[idx+1][0] ; 
                }
                if(nums1[idx]>prev2 && nums2[idx]>prev1) {
                    ans = min(ans, 1+ dp[idx+1][1] ) ; 
                }
                dp[idx][swapped] = ans ; 
            }
        }
        return  dp[1][0] ; 
    }

    int spaceOpt(vector<int>& nums1, vector<int>& nums2){
        int  n = nums1.size() ; 
        int swapp = 0 ; 
        int noswap = 0 ; 
        int currSwap = 0 ; 
        int currNoSwap = 0 ; 
        for(int idx = n-1 ; idx>= 1 ; idx--){
            for(int swapped = 1  ; swapped>= 0 ;swapped--){
                int prev1 = nums1[idx-1] ; 
                int prev2 = nums2[idx-1] ; 
                if(swapped){
                    swap(prev1, prev2) ; 
                }
                int ans = INT_MAX ; 
                if(nums1[idx]>prev1 && nums2[idx]>prev2 ){
                    ans = noswap ; 
                }
                if(nums1[idx]>prev2 && nums2[idx]>prev1) {
                    ans = min(ans, 1+ swapp ) ; 
                }
               // dp[idx][swapped] = ans ; 
               if(swapped){
                   currSwap = ans ; 
               }
               else {
                   currNoSwap = ans; 
               }
               
            }
            swapp = currSwap ; 
            noswap = currNoSwap ; 
        }
        return  min(swapp, noswap) ; 
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) { 
        nums1.insert(nums1.begin(), -1)  ; 
        nums2.insert(nums2.begin(), -1) ; 
        return spaceOpt(nums1, nums2) ; 
        //int n = nums1.size() ; 
        // first comparing 0th index element with the -1 
       // vector<vector<int>>dp(n, vector<int>(2, -1)) ; 
        //return recurMemo(1, nums1, nums2, 0, n, dp) ; 
    }
};