/// https://practice.geeksforgeeks.org/problems/dice-throw5349/1


#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
  public:
    long long solve(int m, int n, int x , int index, long long & ans){
        
        if(x<0){
            return 0 ; 
        }
        if(x==0 && index==n+1){
            ans++; 
            return 1; 
        }
        if(index>n+1){
            return 0 ; 
        }
        
        // travering in  the index dice 
        long long count = 0 ; 
        for(int i = 1 ; i<=m ;i++){
            if(x-i>=0){
               count += solve(m , n, x-i , index+1, ans) ;
        }
           
        }
        return count ; 
    }
    
    long long recur(int dice, int faces, int target){
        if(target<0){
            return 0 ;
        }
        if(dice ==0 &&target != 0){
            return 0 ; 
        }
        if(dice != 0 && target ==0){
            return 0 ; 
        }
        if(dice == 0 && target ==0){
            return 1 ; 
        }
        long long  ans = 0 ; 
        for(int i = 1 ;i<=faces ;i++){
            ans += recur(dice-1, faces, target-i) ; 
        }
        return ans ; 
    }
    
    long long Memorization(int dice, int faces, int target,  vector<vector<long long>>&dp){
        if(target<0){
            return 0 ;
        }
        if(dice ==0 &&target != 0){
            return 0 ; 
        }
        if(dice != 0 && target ==0){
            return 0 ; 
        }
        if(dice == 0 && target ==0){
            return 1 ; 
        }
        if(dp[dice][target] != -1){
            return dp[dice][target] ; 
        }
        long long  ans = 0 ; 
        for(int i = 1 ;i<=faces ;i++){
            ans += Memorization(dice-1, faces, target-i,  dp) ; 
        }
        return dp[dice][target] = ans ; 
    }
    
    long long Tabula(int  dice, int faces, int target){
        
        vector<vector<long long>>dp(dice+1, vector<long long>(target+1, 0)) ; 
        dp[0][0] = 1 ; 
        for(int d = 1 ; d<=dice ; d++){
            for(int t = 1 ;t <= target ;t++){
                long long  ans = 0 ; 
                for(int i = 1 ;i<=faces ;i++){
                    if(t-i>=0){
                        ans += dp[d-1][t-i]  ; 
                    }
                  
                }
                dp[d][t] = ans ; 
            }
        }
        return dp[dice][target] ; 
        /*
        for(int t = target ; t>= 0 ; t--){
            for(int dic = dice ;  dic>= 0 ; dic--){
                if(dic == 0 && t ==0){
                    dp[dic][t] =  1 ; 
                }
                long long  ans = 0 ; 
                for(int i = 1 ;i<=faces ;i++){
                    ans +=dp[dic-1][targe-i]  ; 
                }
                dp[dice][target] = ans ; 
            }
        }*/
    }
    
    long long spaceOpt(int  dice, int faces, int target){
        vector<long long>prev(target+1, 0) ; 
        vector<long long>curr(target+1, 0) ; 
        prev[0] = 1 ; 
        for(int d = 1 ; d<=dice ; d++){
            for(int t = 1 ;t <= target ;t++){
                long long  ans = 0 ; 
                for(int i = 1 ;i<=faces ;i++){
                    if(t-i>=0){
                        ans += prev[t-i]  ; 
                    }
                  
                }
                curr[t] = ans ; 
            }
            prev = curr ; 
        }
        return curr[target] ; 
       
    }
    long long noOfWays(int M , int N , int X) {
        return spaceOpt(N, M, X) ; 
        //vector<vector<long long>>dp(N+1, vector<long long>(X+1, -1)) ; 
       // return Memorization(N, M,  X , dp)  ; 
        //long long ans = 0 ; 
        //solve(M, N, X, 1,ans ) ; 
        
        //return recur(N, M, X) ; 
    }
};