#include<iostream>
using namespace std ;
#include<vector>

int solve(int n, int m , int  k, int idx, vector<int>&v){
    if(idx>=n ){
        if(m==0){
            int curr = 0 ; 
        for(int i = 0  ; i<n ; i++){
            if(v[i]<=0){
                curr= INT_MIN ; 
                break ; 
            }
            else if(v[i]==k){
                curr++ ; 
            }
           // cout<<v[i]<<" " ; 
        }//cout<<endl ; 
        return curr; 
        }
        return INT_MIN ; 
        
    }
     if(m<0){
        return INT_MIN  ; 
     }
    
    // two calls 
    int prev = v[idx-1] ; 
    int ans = 0 ; 
    v[idx] = prev ; 
    ans = max(ans, solve(n, m-prev, k, idx+1, v)) ; 
    v[idx] = prev+1 ; 
    ans = max(ans, solve(n, m-prev-1 , k, idx+1, v));
    v[idx] = prev-1 ; 
    if(prev>1){
        v[idx] = prev-1 ; 
        ans = max(ans, solve(n, m-prev+1, k, idx+1, v)) ; 
    }
    return ans ; 
}
int getMaximumJobs(int n, int m , int  k){
    int ans = 0 ; 
    for(int i =  1 ; i<=n; i++){
        vector<int>v(n, 0) ;
        v[0] = i ; 
        ans = max(ans, solve(n, m-i  , k, 1, v)) ; 
    }
    

    return ans ; 
}



int main(){
    int n, m , k ; 
    cin>>n>>m>>k ; 
    int ans = getMaximumJobs(n, m , k) ; 
    cout<<ans ; 
    return 0 ; 
}