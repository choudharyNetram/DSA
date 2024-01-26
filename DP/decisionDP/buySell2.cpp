/// Best Time to Buy and Sell Stock II



/// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include<map>  
using namespace std;


class Solution {
public:
    int  recur(vector<int>& prices, int n, int idx, bool buyAllowed){
        if(idx==n){
            return 0 ; 
        }
        if(buyAllowed){
            // buy or ignore 
            int ans = -prices[idx]+recur(prices, n,  idx+1,  0) ;
            ans = max(ans, recur(prices, n, idx+1, 1));  
            return ans ;         
        }
        else {
            // sell or ignore 
            int ans  = prices[idx]+ recur(prices, n , idx+1,  1)  ; 
            ans =  max(ans, recur(prices, n, idx+1,  0)) ; 
            return ans  ; 
        }
    }

    int  recurMemo(vector<int>& prices, int n, int idx, int buyAllowed, vector<vector<int>>&dp){
        if(idx==n){
            return 0 ; 
        }
        if(dp[idx][buyAllowed] != -1){
            return dp[idx][buyAllowed] ; 
        }
        if(buyAllowed ==1){
            // buy or ignore 
            int ans = -prices[idx]+recurMemo(prices, n,  idx+1,  0,dp) ;
            ans = max(ans, recurMemo(prices, n, idx+1, 1,dp));  
            return dp[idx][buyAllowed] = ans ;         
        }
        else {
            // sell or ignore 
            int ans  = prices[idx]+ recurMemo(prices, n , idx+1,  1,dp)  ; 
            ans =  max(ans, recurMemo(prices, n, idx+1,  0, dp)) ; 
            return  dp[idx][buyAllowed] = ans  ; 
        }
    }

    int solveTab(vector<int>&prices){
        int n = prices.size() ; 
        vector<vector<int>>dp(n+1, vector<int>(2, 0)) ; 
        for(int idx = n-1 ; idx>= 0 ;idx--){
            for(int buyAllowed = 0 ; buyAllowed<=1 ; buyAllowed++){
                int profit = 0 ; 
                if(buyAllowed ==1){
                    // buy or ignore 
                    int ans = -prices[idx]+dp[idx+1][0] ;
                    ans = max(ans,dp[idx+1][1] );  
                    profit = ans ;         
                }
                else {
                    // sell or ignore 
                    int ans  = prices[idx]+ dp[idx+1][1]  ; 
                    ans =  max(ans, dp[idx+1][0]) ; 
                    profit = ans  ; 
                }
                dp[idx][buyAllowed] = profit ; 
            }
        }
        return dp[0][1] ; 
    }

    int spaceOpt(vector<int>&prices){
        int n = prices.size() ; 
        int nextBuy = 0 ; 
        int nextNotBuy = 0 ; 
        int buy  = 0 ; 
        int notBuy = 0 ; 
        for(int idx = n-1 ; idx>= 0 ;idx--){
            for(int buyAllowed = 0 ; buyAllowed<=1 ; buyAllowed++){
                int profit = 0 ; 
                if(buyAllowed ==1){
                    // buy or ignore 
                    int ans = -prices[idx]+nextNotBuy ;
                    ans = max(ans,nextBuy );  
                    buy = ans ;         
                }
                else {
                    // sell or ignore 
                    int ans  = prices[idx]+ nextBuy  ; 
                    ans =  max(ans, nextNotBuy) ; 
                    notBuy = ans  ; 
                }
            }
            nextBuy = buy ; 
            nextNotBuy = notBuy ; 
        }
        return buy ; 
    }
    int maxProfit(vector<int>& prices) {
        return spaceOpt(prices) ; 
       // return solveTab(prices) ; 
       // int n  = prices.size()  ; 
        //vector<vector<int>>dp(n, vector<int>(2,-1)) ; 
        //return recurMemo(prices, n , 0, 1, dp) ; 
        //return recur(prices, n , 0, 1) ; 
    }
};