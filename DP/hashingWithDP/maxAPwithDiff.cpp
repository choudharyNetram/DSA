/// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size() ; 
        unordered_map<int,int>dp ; 
        int ans = 0 ; 
        for(int i = 0 ; i<n ;i++){
            int temp = arr[i]-difference ; 
            int tempAns = 0 ; 
            if(dp.count(temp)){
                tempAns = dp[temp] ; 
            }
            dp[arr[i]] = 1+tempAns ; 
            ans = max(ans, dp[arr[i]]) ; 
        }
        return ans ; 
    }

/* the below solution without dp takes O(n*n)  time complexity 
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size() ; 
        if(n<=2){
            return n ; 
        }
        int ans  = 0 ; 
        vector<int>dp(n); 
        for(int i = 0 ;i<n ; i++){
            dp[i] = 1 ; 
        }
        for(int i = 1; i<n ; i++){
            for(int j = i-1 ;j>=0 ;j--){
                int diff = arr[i]-arr[j] ; 
                if(diff == difference){
                    int cnt = dp[j] ; 
                    dp[i] = 1+cnt ; 
                    ans = max(ans, dp[i]) ; 
                    break ; 
                }                
            }
        }
        if(ans == 0){
            return 1 ; 
        }
        return ans ; 
    }  */

};


