///  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/



#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include<map>  
using namespace std;


class Solution {
public:
    // is buy allowed, if buy allowed than buy or ignore, if no. of transcation is greater than 2 than  simple return the profit 
    // whenever sell is done than increae the number of transcation 

    int recur(vector<int>& prices, int n , int numTrans,int idx, int buyAllowed ){
        if(idx==n || numTrans>=2){
            return 0 ; 
        }
        if(buyAllowed){
            // buy or ignore 
            int ans = -prices[idx]+recur(prices, n,numTrans,  idx+1,  0) ;
            ans = max(ans, recur(prices, n,numTrans, idx+1, 1));  
            return ans ;         
        }
        else {
            // sell or ignore 
            int ans  = prices[idx]+ recur(prices, n ,numTrans+1, idx+1,  1)  ; 
            ans =  max(ans, recur(prices, n,numTrans, idx+1,  0)) ; 
            return ans  ; 
        }
    }

     int recurMemo(vector<int>& prices, int n , int limit,int idx, int buyAllowed, vector<vector<vector<int>>>&dp ){
        if(idx==n || limit==0){
            return 0 ; 
        }
        if(dp[idx][buyAllowed][limit] != -1){
            return dp[idx][buyAllowed][limit] ;
        }
        int profit = 0 ; 
        if(buyAllowed){
            // buy or ignore 
            int ans = -prices[idx]+recurMemo(prices, n,limit,  idx+1,  0, dp) ;
            ans = max(ans, recurMemo(prices, n,limit, idx+1, 1,dp));  
            profit = max(ans, profit) ;         
        }
        else {
            // sell or ignore 
            int ans  = prices[idx]+recurMemo(prices, n ,limit-1, idx+1,  1,dp); 
            ans =  max(ans, recurMemo(prices, n,limit, idx+1,  0,dp)) ; 
            profit = max(ans, profit)  ; 
        }
        return  dp[idx][buyAllowed][limit] = profit  ; 
    } 

    int solveTab(vector<int>& prices){
        int n = prices.size() ; 
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));  
        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int buyAllowed = 0 ; buyAllowed<=1 ; buyAllowed++ ){
                for(int limit = 1 ; limit<=2 ; limit++){
                    int profit = 0 ; 
                    if(buyAllowed){
                        // buy or ignore 
                        int ans = -prices[idx]+dp[idx+1][0][limit] ;
                        ans = max(ans, dp[idx+1][1][limit]);  
                        profit = max(ans, profit) ;         
                    }
                    else {
                        // sell or ignore 
                        int ans  = prices[idx]+dp[idx+1][1][limit-1] ; 
                        ans =  max(ans, dp[idx+1][0][limit]) ; 
                        profit = max(ans, profit)  ; 
                    }
                    dp[idx][buyAllowed][limit] = profit  ; 
                }
            }
        }
        return dp[0][1][2] ; 
    }

     int spaceOpt(vector<int>& prices){
        int n = prices.size() ; 
        vector<vector<int>>next(2, vector<int>(3, 0)) ; 
        vector<vector<int>>curr(2, vector<int>(3, 0)) ; 

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int buyAllowed = 0 ; buyAllowed<=1 ; buyAllowed++ ){
                for(int limit = 1 ; limit<=2 ; limit++){
                    int profit = 0 ; 
                    if(buyAllowed){
                        // buy or ignore 
                        int ans = -prices[idx]+next[0][limit] ;
                        ans = max(ans, next[1][limit]);  
                        profit = max(ans, profit) ;         
                    }
                    else {
                        // sell or ignore 
                        int ans  = prices[idx]+next[1][limit-1] ; 
                        ans =  max(ans, next[0][limit]) ; 
                        profit = max(ans, profit)  ; 
                    }
                    curr[buyAllowed][limit] = profit  ; 
                }
            }
            next = curr ; 
        }
        return curr[1][2] ; 
    }
    // in this question here we need 3-d dp vector 
    int maxProfit(vector<int>& prices) {
        return spaceOpt(prices) ; 
        /*
        int n = prices.size() ; 
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(3, -1))) ; 
        return recurMemo(prices,n, 2, 0, 1,dp) ; */
    }
};