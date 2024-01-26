// see the google sheet for this 

/*
#include <bits/stdc++.h>
// the below methods is using the memotization

int solveTabul(vector<int> & num, int x){
    vector<int> dp(x+1, INT_MAX) ;
    dp[0]  = 0 ; 
    for(int i = 1 ; i<=x ;i++){
        for(int j = 0 ;j<num.size() ; j++){
            if(i-num[j]>=0 && dp[i-num[j]]!= INT_MAX){
                dp[i] = min(dp[i], dp[i-num[j]]+1) ;
            }
        }
    }
    if(dp[x] == INT_MAX){
        return -1 ; 
    }
    return dp[x] ;
}
int minimumElements(vector<int> &num, int x) {
    int ans = solveTabul(num,  x) ; 
    return ans ; 
}



*/

/* the below methods is using the Recursion + Memotization 

int recurMem(int target, vector<int>&num, vector<int>&dp ){
    if(target == 0){
        return target ; 
    }
    if(target<0){
        return INT_MAX ; 
    }
    int mini = INT_MAX ; 
    if(dp[target]!= -1){
        return dp[target]  ; 
    }
    for(int i = 0 ;i<num.size(); i++){
        
        int ans = recurMem(target-num[i], num, dp) ; 
        if(ans != INT_MAX){
            mini = min(ans+1, mini) ; 
        }
    }
    dp[target]  = mini ; 
    return mini ; 
}
int minimumElements(vector<int> &num, int x)
{  
    vector<int>dp(x+1, -1) ; 
    int ans = recurMem(x, num, dp) ; 
    if(ans == INT_MAX){
        return -1 ; 
    }
    return ans ; 
}  


/* the below solution uses recursion   
int recur(int target, vector<int>&num ){
    if(target == 0){
        return target ; 
    }
    if(target<0){
        return INT_MAX ; 
    }
    int mini = INT_MAX ; 
    for(int i = 0 ;i<num.size(); i++){
        int ans = recur(target-num[i], num) ; 
        if(ans != INT_MAX){
            mini = min(ans+1, mini) ; 
        }
    }
    return mini ; 
}
int minimumElements(vector<int> &num, int x)
{  
    int ans = recur(x, num) ; 
    if(ans == INT_MAX){
        return -1 ; 
    }
    return ans ; 
}  */



#include <bits/stdc++.h>

using namespace std;

int cutSegments(int n, int x, int y, int z) {
  vector<int> dp(n+1, INT_MIN)  ; 
  vector<int>xyz(3) ; xyz[0]=x ; xyz[1] = y ;xyz[2] =  z ; 
  dp[0] = 0 ; 
  for(int i = 1 ;i<=n ;i++){
    // finding the maximum number of segments i can make for size i rod 
    for(int j = 0 ;j<3 ;j++){
      if(i-xyz[j]>= 0 && dp[i-xyz[j]] != INT_MIN){
        dp[i] = max(dp[i], dp[i-xyz[j]]+1)  ; 
      }
    }
  }
  if(dp[n]==INT_MIN){
    return 0; 
  }
  return dp[n] ; 
}

int main() {
  int t;
  cin >> t;
  while(t--){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    cout << cutSegments(n,x,y,z) << endl;
  }
  return 0;
}