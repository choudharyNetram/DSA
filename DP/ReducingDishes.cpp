///   https://leetcode.com/problems/reducing-dishes/description/


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;




class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int time){
        if(index == satisfaction.size()){
            return 0 ; 
        }
        int include = satisfaction[index]*(time+1) + solve(satisfaction, index+1, time+1) ; 
        int exclude = 0 + solve(satisfaction, index+1, time) ;
        return max(include, exclude) ; 
    }

     int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>>&dp){
        if(index == satisfaction.size() ){
            return 0 ; 
        }
        if(dp[index][time] != -1){
            return dp[index][time] ; 
        }

        int include = satisfaction[index]*(time+1) + solveMem(satisfaction, index+1, time+1,dp) ; 
        int exclude = 0 + solveMem(satisfaction, index+1, time, dp) ;
        dp[index][time] = max(include, exclude) ; 
        return dp[index][time] ; 
    }

    int solveTab(vector<int>& satisfaction){
        int n = satisfaction.size() ; 
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)) ; 
        for(int index= n-1 ; index>= 0 ; index--){
            for(int time = index ; time>= 0 ; time--){
                int include = satisfaction[index]*(time+1) + dp[index+1][time+1] ; 
                int exclude = 0+ dp[index+1][time] ; 
                dp[index][time] = max(include, exclude) ; 
            }
        }
        return dp[0][0] ; 
    }

    int solveSpace(vector<int>& satisfaction){
        int n = satisfaction.size() ; 
        // vector<vector<int>>dp(n+1, vector<int>(n+1, 0)) ; 
        vector<int>curr(n+1, 0) ; 
        vector<int>next(n+1, 0) ; 
        for(int index= n-1 ; index>= 0 ; index--){
            for(int time = index ; time>= 0 ; time--){
                int include = satisfaction[index]*(time+1) + next[time+1] ; 
                int exclude = 0+ next[time] ; 
               curr[time] = max(include, exclude) ; 
            }
            next = curr ; 
        }
        return next[0] ; 
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size() ; 
        sort(satisfaction.begin(), satisfaction.end()) ; 
        return solveTab(satisfaction) ; 
       // vector<vector<int>>dp(n+1, vector<int>(n+1, -1)) ; 
        //return solveMem(satisfaction, 0 , 0, dp) ; 
       // return solve(satisfaction, 0 , 0) ; 
    }
};
/* the below solution is also correct, with O(n*n) time complexity 
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end()) ; 
        int ans = INT_MIN ; 
        int n = satisfaction.size() ; 
        for(int i = 0; i<n ;i++){
            // traversing in the vector
            int curr = 0 ; int mul = 1 ; 
            for(int j = i ;j<n ; j++){
                curr += mul*satisfaction[j] ; 
                mul++ ; 
            }
            ans = max(ans, curr) ; 
        }
        if(ans<0){
            return 0 ; 
        }
        return ans ; 
    }
};*/














