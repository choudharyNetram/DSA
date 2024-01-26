/*#include<iostream>
using namespace std ;
#include<map>
#include<vector> 
int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        int n ; 
        cin>>n ; 
        bool flag = 1 ; 

        map<int,pair<int,int>>count ; 
        for(int i = 0 ;i<n ;i++){
            int k ; 
            cin>>k ; 
            count[k].first = k; 
            count[k].second++  ;
            cout<<count[k].first<<" "<<count[k].second<<endl;   
        }
        int size = count.size() ; 
        cout<<size<<" size"<<endl ;
        
        if(size==1){
            if(count[0].first == 0){
                flag = 1 ; 
            }
            else {
                flag = 0 ; 
            }
        }
        
        for(int i = 0 ;i<size-1 ; i++){
            if((abs(count[i+1].first-count[i].first)!=1 )|| count[i].second<count[i+1].second){ 
                flag = 0 ; 
                break; 
            }
        }
        if(flag == 1){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"No"<<endl; 
        }
         
    }
}



#include<iostream>
using namespace std ;
#include<map>
#include<vector> 
int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        int n ; 
        cin>>n ; 
        bool flag = 1 ; 

        map<int,pair<int,int>>count ; 
        for(int i = 0 ;i<n ;i++){
            int k ; 
            cin>>k ; 
            count[k].first = k; 
            count[k].second++  ;
            //cout<<count[k].first<<" "<<count[k].second<<endl;   
        }
        int size = count.size() ; 
        auto it = count.begin();
        if (size == 1) {
            if (it->second.first == 0) {
                flag = 1;
            } else {
                flag = 0;
            }
        } else {
            auto nextIt = it;
            ++nextIt;
            for (; nextIt != count.end(); ++it, ++nextIt) {
                if (abs(nextIt->first - it->first) != 1 || it->second.second < nextIt->second.second) {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag == 1){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"No"<<endl; 
        }
         
    }
}
*/ 


/*
#include<iostream>
using namespace std ;
#include<vector> 
#include<algorithm>
int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        int n ; 
        cin>>n ; 
        vector<int>v(n) ; 
        for(int i = 0 ;i<n ;i++){
            cin>>v[i] ; 
        }
        sort(v.begin(), v.end()) ; 
        long long int ans =  0 ;
        for(int i = 0 ;i<n/2 ; i++){
            ans += v[n-1-i]-v[i] ; 
        }
        cout<<ans<<endl; 
    }
}



#include<iostream>
using namespace std ;
#include<vector> 
#include<algorithm>
int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        int n ; 
        cin>>n ; 
        vector<int>v(n) ; 
        for(int i = 0 ;i<n ;i++){
            cin>>v[i] ; 
        }
        int  count = 0  ; 
        int i = 0 ;
        while(i<n){
            if(v[i]<0){
                count++;  
                while(i<n && v[i]<=0){
                    i++; 
                }
            }
            else {
                i++; 
            }
        }
        long long int sum = 0 ; 
        for(int i = 0 ;i<n ;i++){
            sum += abs(v[i]) ; 
        }
        cout<<sum<<" "<<count<<endl;  
    }
}

*/ 

#include<iostream>
using namespace std ;
int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        long long int  n ; 
        cin>>n ; 
        long long int sum = 0; 
        while(n>0){
            sum += n ; 
            n = n/2 ; 
        }
        cout<<sum<<endl ; 
    }
}