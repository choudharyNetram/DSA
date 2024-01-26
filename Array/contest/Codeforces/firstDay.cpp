#include<iostream>
using namespace std ;
#include<set> 
#include <unordered_set>

void recur(string s, unordered_set<string>&thisset ){
    if(s==""){
        return ; 
    }
    // remove first 
    thisset.insert(s) ; 
    string st1 ; 
    string st2 ; 
    int n = s.size() ; 
    if(n==1){
        st1 = "" ; 
        st2 = "" ; 
    }
    else if(n==2){
        st2 = s[0] ; 
        st1 = s[1] ; 

    }
    else {
        st1 = s.substr(1) ; 
        st2 = s[0]+ s.substr(2) ; 
    }
    if(thisset.find(st1) == thisset.end()){
        recur(st1, thisset) ; 
    }
    if(thisset.find(st2) == thisset.end()){
        recur(st2, thisset) ; 
    }
    
    
}
int findnum(int n, string s){
    unordered_set<string>thisset  ;
    recur(s, thisset) ;  

    int ans = thisset.size() ; 
    return ans ;

}
int main(){
    int t ; 
    cin>>t ; 
    while(t--){
        int n ; 
        string s ; 
        cin>>n ; 
        cin>>s ; 
        int ans = findnum(n, s) ;
        cout<<ans<<endl ; 
    }
    return 0 ; 
}



/*


void recur(int n, int idx, string&s, string curr, unordered_set<string>&thisset){
    if(idx>=n){
        return ; 
    }
    // push or don't push basic thing
    if(idx==n-1){
        if(curr != ""){
            thisset.insert(curr) ;

        }
        cout<<curr<<" "<<idx<<endl ; 
        thisset.insert(curr+s[n-1]) ; 
        return ; 
    }
    if(curr != ""){
        thisset.insert(curr) ; 
    }
    cout<<curr<<" "<<idx<<endl ; 
    recur(n, idx+1, s, curr, thisset) ; 
    curr.push_back(s[idx]) ; 
    recur(n, idx+1, s, curr, thisset) ; 
    curr.pop_back() ; 
}

int findnum(int n, string s){
    unordered_set<string>thisset  ; 
    string curr = "" ; 
    recur(n,0, s, curr,  thisset) ;
    int ans = thisset.size() ; 
    return ans ;

}
*/