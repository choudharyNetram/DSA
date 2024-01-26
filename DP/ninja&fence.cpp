// https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208?leftPanelTab=1 


#include <bits/stdc++.h> 
#define MOD 1000000007 
using namespace std    ; 

// the basic funda in this is that there is to possibilites that last two
// coloor are same or different. 
// for n=2, k =3,  Red, Blue, Green are three colors 
// RR, GG, BB, RG,  RB, GB, GR, BR, BG 
// for calculating for n=3, k =3  
/* two options: first pick this and add the same color as last color 
RG, RB, GB, GR, BR, BG : each has (k-1) choices*/
// second :pick  R, G, B and add this RR, GG, BB , for each one choices (k-1) 
/* the below solutionn uses recursion to solve this question 
*/ 

int add(int a, int b ){
    return ((a%MOD)+(b%MOD))%MOD ; 
}
int multi(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD ; 
}
int recur(int n, int k, vector<int>&dp){
    if(n==0||k==0){
        return 0 ; 
    }
    if(n==1){
        return k ; 
    }
    if(dp[n] != -1){
        return dp[n] ; 
    }
    if (n==2){
        return  add(k, multi(k, k-1))  ; //  k*k
    }
    dp[n] =  add(multi((k-1), recur(n-1, k, dp)),  multi((k-1), recur(n-2, k, dp)) ) ;
    return dp[n] ;  
}
int solveTabul(int n, int k){
    vector<int>dp(n+1, -1) ;
    dp[0] = 0 ; 
    dp[1] = k ; dp[2] = multi(k, k) ;
    for(int i = 3 ;i<= n ;i++){
        dp[i] =   add(multi((k-1), dp[i-1]),  multi((k-1),dp[i-2]) ) ;
    }
    return dp[n] ; 
}
int numberOfWays(int n, int k) {
    vector<int>dp(n+1, -1) ;
    int ans = solveTabul(n, k) ; 
    return ans ; 
}



