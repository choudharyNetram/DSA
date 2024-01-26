/*#include<iostream>
using namespace std ; 
#include<algorithm> 
int main(){
    int t ; 
    cin>>t ; 
    while(t--){
        int n ;
        cin>>n ; 
        int a[n] ;
        int flag = 1 ;  
        for(int i =0;i<n ;i++){
            cin>>a[i];
            if(a[i]%2 != 0){
                flag = 0 ; 
            }
        } 
        if(flag == 1){
            cout<<"YES"<<endl ; 
        }
        else {
            int me = INT_MAX ;
            int mo = INT_MAX ;  
            for(int i = 0 ;i<n ;i++){
                if(a[i]%2 == 0){
                    me = min(me, a[i]);
                }
                else {
                    mo = min(mo, a[i]);
                }
            }
            if(me == INT_MAX){
                cout<<"YES"<<endl ; 
            }
            else if (me>mo){
                cout<<"YES"<<endl ; 
            }
            else {
                cout<<"NO"<<endl; 
            }
        }
        

    }
    return 0 ; 
}
*/



// F. Ira and Flamenco
/*
#include<iostream>
using namespace std ; 
#include<algorithm> 
int main(){
    int t ; 
    cin>>t ; 
    while(t--){
        int n ,m;
        cin>>n>>m ; 
        int a[n] ;
        for(int i = 0  ;i<n ;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int ans = 0 ; 
        for(int i = 0 ;i<n-m; i++){
            int count = 0 ; 
            int  j = i ;  
            int c = 1 ; 
            while(count<m && j<n-1){
                if(a[j+1]==a[j]){
                    c = 2*c; 
                }
                else if (a[j+1]==a[j]+1){
                    count++ ; 
                }
                else{
                    break;
                }
                j++; 
            }
            if(count == m){
                ans += c; 
            }

        }
        cout<<ans<<endl; 
    }
    return 0 ; 
}*/

#include <iostream>
using namespace std;
#include<vector> 
#include<algorithm> 
int main() {
    int t ; 
    cin>>t ; 
    while(t--){
        int n,k, l ;
        cin>>n>>k>>l ; 
        int a[n] ; 
        int b[n] ;
        vector<int> lsongs  ; 
        for(int i = 0; i<n ;i++){
            cin>>a[i]>>b[i] ;
            if(b[i]==l){
                lsongs.push_back(a[i]) ;
            }
        }
        sort(lsongs.begin(), lsongs.end()) ;
        int n1 = lsongs.size() ;
        if(n1==0){
            cout<<-1<<endl ;
        }
        else {
            int  ans = 0 ; 
        for(int i = 0;i<k ;i++){
            ans += lsongs[n1-1-i] ;
        }
        cout<<ans<<endl ; 
        }
        
        
    }
	return 0;
}
