/* #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(string curr, char ch){
    int n = curr.size() ; 
    if(n==0){
        return true ; 
    }
    if(curr[n-1] != ch){
        return true ; 
    }
    return false ; 
}
int solve(int index, string s , string curr, int n){
    if(curr.size()==3){
        return 1 ; 
    }
    if(curr.size()>3 || index>=n){
        return 0 ; 
    }
    int ans = 0 ; 
    if(isValid(curr, s[index])){
        ans += solve(index+1, s, curr+s[index] , n) ; 
        
    }
    ans += solve(index+1, s, curr, n ) ; 
    return ans ; 
}

int main() {
    int t ; 
    cin>>t ;  
    while(t--){
        string s ; 
        cin>>s ; 
        int n = s.size() ; 
        int ans = solve(0, s,"", n) ;  
        cout<<ans<<endl ; 
    }
    return 0;
}
*/ 

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(string curr, char ch){
    int n = curr.size() ; 
    if(n==0){
        return true ; 
    }
    if(curr[n-1] != ch){
        return true ; 
    }
    return false ; 
}
int solve(int index, string s , string curr, int n, vector<int>&dp){
    if(curr.size()==3){
        return 1 ; 
    }
    if(curr.size()>3 || index>=n){
        return 0 ; 
    }
    if(dp[index] != -1){
        return dp[index] ; 
    }
    int ans = 0 ; 
    if(isValid(curr, s[index])){
        ans += solve(index+1, s, curr+s[index] , n, dp) ; 
        
    }
    ans += solve(index+1, s, curr, n, dp ) ; 
    return dp[index] = ans ; 
}

int main() {
    int t ; 
    cin>>t ;  
    while(t--){
        string s ; 
        cin>>s ; 
        int n = s.size() ; 
        vector<int>dp(n, -1) ; 
        int ans = solve(0, s,"", n, dp) ;  
        cout<<ans<<endl ; 
    }
    return 0;
}
*/



