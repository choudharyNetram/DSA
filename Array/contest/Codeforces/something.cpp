#include<iostream>
using namespace std ;
#include<map> 
#include<vector>
#include<unordered_map> 

int newWaterLevel(int n, vector<int>&wet, vector<vector<int>>&mat, unordered_map<int,bool>& mp ){
    // iterate over all neighbours of wet elements 
    int siz = wet.size() ; 
    int waterLevel = 1e8 ; 
    for(int i = 0 ; i<siz ; i++){
        int uniq = wet[i] ; 
        int row = uniq/n ; 
        int col = uniq%n ; 
        if(row<n-1 && mp[(row+1)*n+col]==0){
            waterLevel = min(waterLevel, mat[row+1][col]) ; 
        }
        if(row>0 && mp[(row-1)*n + col]==0){
            waterLevel = min(waterLevel, mat[row-1][col]) ; 
        }
        if(col<n-1 && mp[row*n+col+1]==0){
            waterLevel = min(waterLevel, mat[row][col+1]) ; 
        }
        if(col>0 && mp[row*n + col-1]==0){
            waterLevel = min(waterLevel, mat[row][col-1]) ; 
        }

    }
    return waterLevel ; 
}

// traverse to all neighbours of wet element
bool traverseNeighb(int n, int &waterLevel,vector<int>&wet, vector<vector<int>>&mat, vector<vector<char>>&ans, unordered_map<int,bool>& mp  ){
    int idx = 0 ; 
    while(idx<wet.size()){
        ///cout<<idx<<" " ; 
        int uniq = wet[idx] ; 
        int row = uniq/n ; 
        int col = uniq%n ; 
        if(row==0 || row == n-1 || col == 0 || col ==n-1){
            return 1 ; 
        }
        if(row<n-1){
            int new_uniq = (row+1)*n+col ; 
            if( mp[new_uniq] == 0 &&  waterLevel >= mat[row+1][col] ){
                wet.push_back(new_uniq)  ; 
                mp[new_uniq] = 1 ; 
            }
        }
        if(row>0){
            int new_uniq = (row-1)*n+col ; 
            if( mp[new_uniq] == 0 && waterLevel >= mat[row-1][col] ){
                wet.push_back(new_uniq) ; 
                mp[new_uniq] = 1 ; 
            }
             
        }
        if(col<n-1){
            int new_uniq = row*n+col+1 ; 
            if(mp[new_uniq] == 0 && waterLevel >= mat[row][col+1]){
                wet.push_back(new_uniq) ; 
                mp[new_uniq] = 1 ; 
            }
        }
        if(col>0){
            int new_uniq = row*n+col-1 ; 
            if(mp[new_uniq] == 0 && waterLevel >= mat[row][col-1]){
                wet.push_back(new_uniq) ; 
                mp[new_uniq] = 1 ; 
            }
        }
        idx++  ; 
    }
    //cout<<endl ; 
    return 0 ; 
}

void solve(vector<vector<int>>& mat, int n,vector<vector<char>>&ans ){
    vector<int>wet ; 
    // a vector, stores the pair i, j
    // i = u / n; j = u % n;
    // when water level rises then find the minimum of dry neighbours
    int waterLevel = mat[n/2][n/2] ; 
    wet.push_back(n*(n/2)+ (n/2)) ; 
    unordered_map<int,bool> mp ; 
    mp[n*(n/2)+ (n/2)] = true ; 
    int b = 0 ; 
    while(traverseNeighb(n, waterLevel,wet, mat, ans, mp) == 0){
        if(b>7){
            break ; 
        }
        // find the minimum of all neighbour dry and make the water level equal to that 
        //cout<<waterLevel<<endl ; 
        waterLevel = newWaterLevel(n, wet, mat, mp) ; 
        //cout<<waterLevel<<" waterLevel"<<" " ; 
        b++ ; 
    }
    
    int siz = wet.size() ; 
    for(int i = 0 ; i<siz ; i++){
        int uniq = wet[i] ; 
        int row = uniq/n ; 
        int col = uniq%n ; 
        ans[row][col] = 'W' ; 
    }
    
    return ; 
}
int main(){
    int n ; 
    cin>>n ; 
    vector<vector<int>>mat(n, vector<int>(n)) ; 
    for ( int i = 0 ;i<n ; i++){
        for (int j = 0 ; j<n ; j++){
            cin>>mat[i][j] ; 
        }
    }
    vector<vector<char>>ans(n, vector<char>(n, '.')) ; 
    solve(mat, n, ans) ; 
    for ( int i = 0 ;i<n ; i++){
        for (int j = 0 ; j<n ; j++){
            cout<<ans[i][j] ; 
        }
        cout<<endl ; 
    }
    return 0 ; 
}