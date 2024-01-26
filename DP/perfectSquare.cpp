/// https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1


#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 

class Solution{
	public:
	int recur(int n){
	    if(n<=0){
	        return 0 ; 
	    }
	    int ans = n ; 
	    for(int i = 1 ;i*i<=n ;i++){
	        int temp = i*i ; 
	        ans = min(ans, 1+recur(n-temp)) ; 
	    }
	    return ans ; 
	}
	int recurMem(int n, vector<int>&dp){
	    if(n<=0){
	        return 0 ; 
	    }
	    if(dp[n] != -1){
	        return dp[n] ; 
	    }
	    int ans = n ; 
	    for(int i = 1 ;i*i<=n ;i++){
	        int temp = i*i ; 
	        ans = min(ans, 1+recurMem(n-temp, dp)) ; 
	    }
	    dp[n] = ans ; 
	    return dp[n] ; 
	}
	
	int tabul(int n){
	    vector<int>dp(n+1, INT_MAX) ; 
	    dp[0] = 0 ; 
	    for(int i = 1; i<=n ; i++){
	        for(int j = 1 ; j*j<=n ;j++){
	            int temp = j*j ; 
	            if(i-temp>=0){
	                dp[i] = min(dp[i],1+ dp[i-temp]) ; 
	            }
	        }
	    }
	    return dp[n] ;
	}
	int MinSquares(int n)
	{
	    //vector<int>dp(n+1, -1) ; 
	    return tabul(n) ; 
	    
	}
};

/*
class Solution{
	public:
	int MinSquares(int n)
	{
	    // total weight 
	    int x = sqrt(n) ; 
	    vector<int>dp(n+1, INT_MAX) ; /// the number at dp[i]
	    dp[0] = 0 ; 
	    for(int i = 0 ;i<=n ;i++){
	        for(int j = 0 ;j<=x ;j++){
	            if(i-(j*j)  >= 0 && dp[i-j*j] != INT_MAX){
	                dp[i] = min(dp[i],  dp[i-j*j]+1) ;
	            }
	        }
	    }
	    return dp[n] ;
	    
	}
}; */