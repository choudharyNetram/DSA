////    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include<map>  
using namespace std;





class Solution {
public:
    int recur(vector<int>& prices, int n , int idx, int buyAllowed, int fee ){
        if(idx==n ){
            return 0 ; 
        }
        if(buyAllowed){
            // buy or ignore 
            int ans = -prices[idx]+recur(prices, n,  idx+1,  0, fee) ;
            ans = max(ans, recur(prices, n, idx+1, 1, fee));  
            return ans ;         
        }
        else {
            // sell or ignore 
            int ans  = prices[idx]+ recur(prices, n , idx+1,  1,fee)-fee  ; 
            ans =  max(ans, recur(prices, n, idx+1,  0, fee)) ; 
            return ans  ; 
        }
    }

     int recurMemo(vector<int>& prices, int n ,int idx, int buyAllowed, vector<vector<int>>&dp, int fee ){
        if(idx==n ){
            return 0 ; 
        }
        if(dp[idx][buyAllowed] != -1){
            return dp[idx][buyAllowed] ;
        }
        int profit = 0 ; 
        if(buyAllowed){
            // buy or ignore 
            int ans = -prices[idx]+recurMemo(prices, n,  idx+1,  0, dp, fee) ;
            ans = max(ans, recurMemo(prices, n, idx+1, 1,dp, fee));  
            profit = max(ans, profit) ;         
        }
        else {
            // sell or ignore 
            int ans  = prices[idx]+recurMemo(prices, n , idx+1,  1,dp,fee)-fee; 
            ans =  max(ans, recurMemo(prices, n, idx+1,  0,dp,fee)) ; 
            profit = max(ans, profit)  ; 
        }
        return  dp[idx][buyAllowed] = profit  ; 
    } 

    int solveTab(vector<int>& prices, int fee){
        int n = prices.size() ; 
        vector<vector<int>>dp(n+1, vector<int>(2, 0)) ; 
        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int buyAllowed = 0 ; buyAllowed<=1 ; buyAllowed++ ){
                    int profit = 0 ; 
                    if(buyAllowed){
                        // buy or ignore 
                        int ans = -prices[idx]+dp[idx+1][0] ;
                        ans = max(ans, dp[idx+1][1]);  
                        profit = max(ans, profit) ;         
                    }
                    else {
                        // sell or ignore 
                        int ans  = prices[idx]+dp[idx+1][1]-fee ; 
                        ans =  max(ans, dp[idx+1][0]) ; 
                        profit = max(ans, profit)  ; 
                    }
                    dp[idx][buyAllowed] = profit  ; 
                }

        }
        return dp[0][1] ; 
    }

     int spaceOpt(vector<int>& prices, int fee){
        int n = prices.size() ; 
        vector<int>next(2, 0) ; 
        vector<int>curr(2, 0) ; 

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int buyAllowed = 0 ; buyAllowed<=1 ; buyAllowed++ ){
                    int profit = 0 ; 
                    if(buyAllowed){
                        // buy or ignore 
                        int ans = -prices[idx]+next[0] ;
                        ans = max(ans, next[1])    ; 
                        profit = max(ans, profit) ;         
                    }
                    else {
                        // sell or ignore 
                        int ans  = prices[idx]+next[1]-fee ; 
                        ans =  max(ans, next[0]) ; 
                        profit = max(ans, profit)  ; 
                    }
                    curr[buyAllowed] = profit  ; 
                }
            next = curr ; 
        }
        return curr[1] ; 
    }
    int maxProfit(vector<int>& prices, int fee) {
        return spaceOpt(prices, fee) ; 
    
     // int n = prices.size() ; 
      //  vector<vector<int>>dp(n, vector<int>(2, -1)) ; 
       // return recurMemo(prices,n, 0, 1,dp, fee) ; 
      // return recur(prices,  n, 0, 1, fee) ;        
    }
};