/* Minimum Cost For Tickets

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.
*/
#include<iostream>
using namespace std ; 
#include<algorithm>
#include<vector>
#include<queue>
class Solution {
public:
    #include<vector>

int recurs(int index, int n, vector<int>&days, vector<int>&cost){
    if(index>=n){
        return 0; 
    } 
   // if we select the 1 day pass 
    int a = recurs(index+1, n, days, cost)+cost[0] ; 
    // if we select the 7 day pass(ticket) 
    int i = index ; 
    while(i<n && days[i]-7<days[index]){
        i++ ; 
    }

    int b = recurs(i, n, days, cost)+cost[1] ; 
    int j = index ; 
    while(j<n && days[j]-30<days[index]){
        j++ ; 
    }

    int c= recurs(j, n, days, cost)+cost[2] ; 
    int ans = min(a,min(b,c)) ; 
    return ans ; 
}


int solveMemo(int index, int n, vector<int>&days, vector<int>&cost, vector<int>&dp){
    if(index>=n){
        return 0; 
    } 
     if(dp[index]!=-1){
        return dp[index] ; 
    }
   // if we select the 1 day pass 
    int a = solveMemo(index+1, n, days, cost, dp)+cost[0] ; 
    // if we select the 7 day pass(ticket) 
   
    int i = index ; 
    while(i<n && days[i]-7<days[index]){
        i++ ; 
    }

    int b = solveMemo(i, n, days, cost, dp)+cost[1] ; 
    int j = index ; 
    while(j<n && days[j]-30<days[index]){
        j++ ; 
    }

    int c= solveMemo(j, n, days, cost,dp)+cost[2] ; 
    dp[index] = min(a,min(b,c)) ; 
    return dp[index] ; 
}

int solveTabula( int n, vector<int>&days, vector<int>&cost){
    vector<int>dp(n+1, -1)  ;
    dp[n] = 0 ; 
   for(int k = n-1 ; k>=0; k--){
       // if we select the 1 day pass 
        int a = dp[k+1]+cost[0] ; 
        // if we select the 7 day pass(ticket) 
    
        int i = k ; 
        while(i<n && days[i]-7<days[k]){
            i++ ; 
        }

        int b = dp[i]+cost[1] ; 
        int j = k ; 
        while(j<n && days[j]-30<days[k]){
            j++ ; 
        }

        int c= dp[j]+cost[2] ; 
        dp[k] = min(a,min(b,c)) ; 
   }
   return dp[0] ;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ; 
        vector<int>dp(n+1, -1)  ;
        return solveTabula( n, days, costs) ; 

        /* the below is the most efficient approach for this, it using constant space O(30), 
        monthly array maximum contains 30 values at max 
        */
       int n = days.size() ; 
        /*
        vector<int>dp(n+1, -1)  ;
        return solveTabula( n, days, costs) ; */
        queue<pair<int,int>> monthly ; 
        queue<pair<int,int>> weekly ; 
        int ans = 0; 
        for(int day: days){
            //  step 1 : remove the expired days 
            while(!monthly.empty() && monthly.front().first + 30 <= day){
                monthly.pop() ; 
            }
            while(!weekly.empty() && weekly.front().first + 7 <= day){
                weekly.pop() ; 

            }
            // push the current day 
            weekly.push(make_pair(day, ans+costs[1])) ; 
            monthly.push(make_pair(day, ans+costs[2])) ; 
            ans = min(ans+costs[0],  min(monthly.front().second, weekly.front().second)) ; 
        }
        return ans ; 
    }
};