

/// https://leetcode.com/problems/minimum-sideway-jumps/




#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 

class Solution {
public:
    // lines 1, 2, 3 
    int  solve(vector<int>& obstacles, int n,  int index, int line){
        if(index==n){
            return 0 ; 
        }
        if(obstacles[index+1] != line){
            return solve(obstacles, n , index+1, line) ; 
        }
        else {
            // sideways jump 
            int ans  = INT_MAX ; 
            for(int i = 1 ; i<= 3 ; i++){
                if(line != i && obstacles[index] != i){
                    ans = min(ans, 1+solve(obstacles, n, index, i)) ; 
                }
            }
            return ans ; 
        }
        
    }
    int  solveMem(vector<int>& obstacles, int n,  int index, int line, vector<vector<int>>&dp){
        if(index==n-1){
            return 0 ; 
        }
        if(dp[index][line]  != -1){
            return dp[index][line] ; 
        }
        if(obstacles[index+1] != line){
            return solveMem(obstacles, n , index+1, line, dp) ; 
        }
        else {
            // sideways jump 
            int ans  = INT_MAX ; 
            for(int i = 1 ; i<= 3 ; i++){
                if(line != i && obstacles[index] != i){
                    ans = min(ans, 1+solveMem(obstacles, n, index, i, dp)) ; 
                }
            }
            dp[index][line] = ans; 
            return ans ; 
        }
        
    }

    int solvetab(vector<int>& obstacles){
        int n= obstacles.size()-1 ; 
        vector<vector<int>>dp(n+1,vector<int>(4, 0)) ; 
        dp[n][1] = 0 ; dp[n][2] = 0 ; dp[n][3] = 0 ;  
        for(int index = n-1  ; index >= 0 ; index--){
            for(int line = 1 ; line <=3 ; line++){
                if(obstacles[index+1] != line){
                    dp[index][line] =  dp[index+1][line] ; 
                }
                else {
                    // sideways jump 
                    int ans  = 1e9  ; 
                    for(int i = 1 ; i<= 3 ; i++){
                        if(line != i && obstacles[index] != i){
                            ans = min(ans, 1+dp[index+1][i]) ; 
                        }
                    }
                    dp[index][line] = ans; 
                }
                
            }
        }
        return min(dp[0][2], min(1+dp[0][1], 1+dp[0][3])) ; 
    }
    
    int solvespaceOpt(vector<int>& obstacles){
        int n= obstacles.size()-1 ; 
        vector<int>curr(4, INT_MAX) ; 
        vector<int>next(4, INT_MAX); 
        next[1] = 0 ; next[0] = 0 ; next[2] = 0 ; next[3] = 0 ;  
        for(int index = n-1  ; index >= 0 ; index--){
            for(int line = 1 ; line <=3 ; line++){
                if(obstacles[index+1] != line){
                    curr[line] =  next[line] ; 
                }
                else {
                    // sideways jump 
                    int ans  = 1e9  ; 
                    for(int i = 1 ; i<= 3 ; i++){
                        if(line != i && obstacles[index] != i){
                            ans = min(ans, 1+next[i]) ; 
                        }
                    }
                    curr[line] = ans; 
                }
                
            }
            next = curr ; 
        }
        return min(curr[2], min(1+curr[1], 1+curr[3])) ; 
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() ; 
        return solvespaceOpt(obstacles) ; 
        //vector<vector<int>>dp(n+1,vector<int>(4, -1)) ; 
        //return solveMem(obstacles, n ,0 , 2 , dp) ; 
    }
};




/*  the below solution is also correct, but it takes some extra time

class Solution {
public:
    // lines 1, 2, 3 
    bool isSafe(vector<int>& obstacles, int newIndex, int line,  vector<vector<bool>>&visited){
        if( !visited[newIndex][line]  &&  obstacles[newIndex] != line){
            return true ;
        }
        return false ; 
    }
    void  solve(vector<int>& obstacles, int n,  int index, int line, int curr,  int &ans,  vector<vector<bool>>&visited){
        if(index==n){
            ans = min(curr, ans) ;
            return; 
        }
        // sending frog to next in same line 
        visited[index][line] = true ;
        if(line == 2){
            if(isSafe(obstacles, index+1, line, visited)){
                solve(obstacles, n, index+1, line, curr, ans, visited) ; 
            }
            
            // sending it to upper line if upper line exist 
            if(isSafe(obstacles, index, line-1, visited)){
                solve(obstacles, n, index, line-1, curr+1, ans, visited) ; 
            }

            // sending from to it bottom line if bottom line exist 
            if(isSafe(obstacles, index, line+1, visited)){
                solve(obstacles, n,  index, line+1, curr+1, ans, visited) ; 
            }
        }
        if(line == 1){
            if(isSafe(obstacles, index+1, line, visited)){
                solve(obstacles, n, index+1, line, curr, ans, visited) ; 
            }
            
            // sending it to upper line if upper line exist 
            if(isSafe(obstacles, index, line+1, visited)){
                solve(obstacles, n, index, line+1, curr+1, ans, visited) ; 
            }

            // sending from to it bottom line if bottom line exist 
            if(isSafe(obstacles, index, line+2, visited)){
                solve(obstacles, n,  index, line+2, curr+1, ans, visited) ; 
            }
        }
        if(line == 3){
            if(isSafe(obstacles, index+1, line, visited)){
                solve(obstacles, n, index+1, line, curr, ans, visited) ; 
            }
            
            // sending it to upper line if upper line exist 
            if(isSafe(obstacles, index, line-1, visited)){
                solve(obstacles, n, index, line-1, curr+1, ans, visited) ; 
            }

            // sending from to it bottom line if bottom line exist 
            if(isSafe(obstacles, index, line-2, visited)){
                solve(obstacles, n,  index, line-2, curr+1, ans, visited) ; 
            }
        }
        visited[index][line] = false;
        
    }


    

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() ; 
        int ans = INT_MAX ;  
        int line  = 2 ; 
        int curr = 0 ; 
        vector<vector<int>>dp(n, vector<int>(4,-1)) ; 
        vector<vector<bool>>visited(n+1,vector<bool>(4,0)) ; 
        solve(obstacles, n , 0, line, curr, ans, visited, dp) ; 
        return ans ; 
    }
};*/