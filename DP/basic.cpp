// Devide problems into some parts and use 

// Quote of the DP: those who forgot the past, are condemned to repeat it

//    Top-Down:- Recursion+ Memoization 
// bottom-up :- Tabulation 
//  space optimisation 

// overlapping sub-problems 


// the below methods uses the Recursion+ Memoization 
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int>fibNum){
    if(n<=1){
        return n; 
    }
    if(fibNum[n]!= -1){
        return fibNum[n]  ; 
    }
    else {
        return fibonacci(n-1, fibNum)+fibonacci(n-2,   fibNum) ; 
    }

}
int main()
{   
    int n ; 
    cin>>n ; 
    vector<int>fibNum(n+1, -1)   ; 
    int ans =  fibonacci(n,  fibNum) ; 
    cout<<ans<<endl ; 
    return 0 ; 
}



//  the below method uses the tabulation apporach 
int main()
{   
    int n ; 
    cin>>n ; 
    vector<int>fibNum(n+1, -1)   ; 
    fibNum[0] = 0  ; 
    fibNum[1] = 1 ; 
    for(int i = 2 ;i<=n ;i++){
        fibNum[i]= fibNum[i-1]+fibNum[i-2] ;
    }
    cout<<fibNum[n]<<endl ;
    return 0 ; 
}



/// Space-optimisation 

int main()
{   
    int n ; 
    cin>>n ; 
    int prev2 = 0  ; 
    int prev1 = 1 ; 

    for(int i = 2 ;i<=n ;i++){
        int curr = prev1 ; 
        prev1 = prev1+prev2 ;
        prev2 = curr ; 
    }
    cout<<prev1<<endl ;
    return 0 ; 
}







