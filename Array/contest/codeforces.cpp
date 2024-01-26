#include<iostream>
using namespace std ; 
#include<algorithm> 
int main(){
    int t ; 
    cin>>t ; 
    while(t--){
        int n,k ; 
        cin>>n>>k ; 
        int a[n]  ;
        int b[n] ;
        int c[n]  ; 
        int visi[n] ;
        for(int i = 0;i<n ;i++){
            cin>>a[i];
            c[i] = a[i] ;
            visi[i] = 0 ; 
        }
        for(int i = 0;i<n ;i++){
            cin>>b[i];
        }
        sort(a, a+n);
        sort(b,b+n);
        for(int i = 0 ;i<n;i++){
            for(int j = 0 ;j<n;j++){
                if(visi[j]==0 && c[i]==a[j]){
                    cout<<b[j]<<" ";
                    visi[j]= 1 ;  
                    break ; 
                }
            }
        }
        cout<<endl; 
    }
}

/*
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int a[n];
        int b[n];

        unordered_map<int, vector<int>> indexMap; // Map to store vectors of indices

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            indexMap[a[i]].push_back(i); // Store indices of elements in a[]
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            int x = a[i];
            int index = indexMap[x].back(); // Retrieve last index from vector
            indexMap[x].pop_back(); // Remove the used index

            cout << b[index] << " ";
        }

        cout << endl;
    }

    return 0;
}


*/