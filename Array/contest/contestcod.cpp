#include<iostream>
using namespace std ; 
int main(){
    int t ; 
    cin>>t ; 
    while(t--){
        int n, k , x ;
        cin>>n>>k>>x ; 
        if(x!=1){
            cout<<"YES"<<endl; 
            for(int i = 0 ;i<n ; i++){
                cout<<1<<" "; 
            }
            cout<<endl; 
        }
        else {
            if(n%2 == 0 ){
                if(k>=2){
                    cout<<"YES"<<endl; 
                    for(int i = 2 ;i<=n ; i=2*i){
                        cout<<2<<" " ; 
                    }
                    cout<<endl;   
                }
                else {
                    cout<<"No"<<endl;  
                }
                
            }
            else if (k<=2){
                cout<<"NO"<<endl; 
            }
            else {
                cout<<"YES"<<endl ; 
                cout<<3<<" " ; 
                for(int i = n-1 ; i>0 ; i=i+2  ){
                    cout<<2<<" "<<" " ;
                }
                cout<<endl; 

            }
        }

    }
}
