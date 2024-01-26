#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int recurs(int n,  int a[], int curr, int prev){
        if(curr== n){
            return 0 ; 
        }
        // include case 
        int take = 0 ; 
        if(prev==-1 || a[curr]>a[prev]){
            take =  1+recurs(n, a, curr+1,  curr) ; 
        }
        int exclude = 0+ recurs(n, a , curr+1, prev) ; 
        return max(take, exclude) ; 
    }
    
    
    int Memorization(int n,  int a[], int curr, int prev, vector<vector<int>>&dp){
        if(curr>= n){
            return 0 ; 
        }
        // include case 
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1] ; 
        }
        int take = 0 ; 
        if(prev==-1 || a[curr]>a[prev]){
            take =  1+Memorization(n, a, curr+1,  curr, dp) ; 
        }
        int exclude = 0+ Memorization(n, a , curr+1, prev, dp) ; 
        return dp[curr][prev+1] = max(take, exclude) ; 
    }
    
    
    int solveTab(int n, int a[]){
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)) ;
        for(int curr = n-1 ; curr>= 0 ;curr--){
            for(int prev = curr-1 ; prev>= -1 ; prev--){
                int take = 0 ; 
                if(prev==-1 || a[curr]>a[prev]){
                    take =  1+dp[curr+1][curr+1]  ; 
                }
                int exclude = 0+dp[curr+1][prev+1] ; 
                dp[curr][prev+1] = max(take, exclude) ; 
                
            }
        }
        return dp[0][0] ; 
    }
    
    int binarySearch(int n, int a[]){
        if(n==0){
            return 0; 
        }
        vector<int>ans ; 
        ans.push_back(a[0]) ; 
        for(int i = 1 ;i<n ;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]) ; 
            }
            else {
                //  finding the just big element from the a[i]  
                int index = lower_bound(ans.begin(), ans.end(), a[i])-ans.begin() ; 
                ans[index] = a[i] ; 
                
            }
        }
        return ans.size() ; 
    }
     int longestSubsequence(int n, int a[])
    {
        int prev = -1 ; //  index of previous element 
        int curr = 0 ; // index of current element 
        return binarySearch(n,a ) ; 
       // return solveTab(n, a) ; 
        //vector<vector<int>>dp(n, vector<int>(n+1, -1)) ; 
        //return Memorization(n, a , curr, prev, dp) ; 
        //return recurs(n , a, curr, prev) ; 
    }
    
    
    /*
    int longestSubsequence(int n, int a[])
    {
       // first make a DAG, make adjlist of all numbers 
       unordered_map<int,list<int>> adj ; 
       vector<int>dp(n, 1) ; 
       for(int i = 0  ; i<n-1 ;i++){
           for(int j = i+1; j<n ;j++){
               if(a[j]>a[i]){
                   dp[j] = max(dp[j], dp[i]+1) ; 
               }
           }
       }
       int ans = INT_MIN ; 
       for(int i = 0 ;i<n ;i++){
           ans = max(ans, dp[i]) ; 
       }
       return ans ; 
       
    }*/
};

// Russian  Doll envelopes 

///   https://leetcode.com/problems/russian-doll-envelopes/description/
/// this is also same problem like the LIS 
// but first we have to sort the vector based on width and then using new height vector, we can find the sorted 

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1]; // if width is same then sort in decending  order of height 
    }
    return a[0] < b[0]; 
}
    int binarySearch(int n, vector<int>& height){
        if(n==0){
            return 0; 
        }
        vector<int>ans ; 
        ans.push_back(height[0]) ; 
        for(int i = 1 ;i<n ;i++){
            if(height[i]>ans.back()){
                ans.push_back(height[i]) ; 
            }
            else {
                //  finding the just big element from the a[i]  
                int index = lower_bound(ans.begin(), ans.end(), height[i])-ans.begin() ; 
                ans[index] = height[i] ; 
                
            }
        }
        return ans.size() ; 
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size() ; 
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int>height(n) ; 
        for(int i = 0 ;i<n ;i++){
            height[i] = envelopes[i][1] ; 
        }
        return binarySearch(n, height) ; 
       /* vector<int>dp(n, 1) ; 
        for(int i = 0 ;i<n-1 ;i++){
            for(int j = i+1 ; j<n ;j++){
                if(envelopes[j][0]>envelopes[i][0] && envelopes[j][1]>envelopes[i][1]){
                    dp[j] = max(dp[j], dp[i]+1) ; 
                }
            }
        }
        int ans = INT_MIN ; 
        for(int i = 0 ;i<n ;i++){
            ans = max(ans, dp[i]) ; 
        }
        return ans ;*/
    }
};




