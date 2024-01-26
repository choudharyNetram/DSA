/// https://leetcode.com/problems/unique-binary-search-trees/


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    // this problem is also similar to Catlan number. we can do this question by just a formula 
///   (2n)! / ((n + 1)! n!)
    int solve(int n,  vector<int>&dp){
        if(n<=0){
            return 0 ; 
        }
        if(n==1){
            return 1 ; 
        }
        if(dp[n] != -1){
            return dp[n] ; 
        }
        // pick one node from it. 
        int ans = 0 ; 
        for(int i = 1 ;i<=n ; i++){
            // root is the i 
                int left = solve(i-1, dp) ; 
                int  right = solve(n-i, dp) ; 
                if(left == 0 || right ==0){
                    ans += left + right ; 
                }
                else {
                    ans += left*right ;
                }
        }
        return dp[n]= ans ; 
    }
    int solve1(int n,  vector<int>&dp){
        if(n<=1){
            return 1 ; 
        }
       
        if(dp[n] != -1){
            return dp[n] ; 
        }
        // pick one node from it. 
        int ans = 0 ; 
        for(int i = 1 ;i<=n ; i++){
            // root is the i 
            ans +=  solve1(i-1, dp)*solve1(n-i, dp) ; 
        }
        return dp[n]= ans ; 
    }

    int solveTab(int n ){
        vector<int>dp(n+1, 0) ; 
        dp[0] = 1 ; dp[1] =1 ; 
        // i is denoting the number of nodes 
        for(int i = 2 ; i<=n ; i++){
            //  j denotes the root node 
            int ans = 0 ; 
            for(int j = 1 ;j<=i ; j++){
                // root is the i 
                ans +=  dp[j-1]*dp[i-j] ; 
            }
            dp[i]= ans ; 
        }
        return dp[n];
    }
    int numTrees(int n) {
        return solveTab(n) ; 
        //vector<int>dp(n+1, -1) ; 
       // return solve1(n, dp) ; 
    }
};