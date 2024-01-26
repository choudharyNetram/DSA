#include<iostream>
using namespace std;
// spiral order matrix traversal 
/// see on leetcode, what is the question
/*
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rowst = 0;
    int n = matrix.size() ;
    int m = matrix[0].size() ;
    int rowen = n-1 ;
    int colst = 0 ;
    int colen = m-1 ;
    vector<int> ans  ; 
    while(rowst<= rowen && colst<=colen){
        for(int i= colst ; i<=colen && rowst<= rowen  ;i++){
        //cout<<matrix[rowst][i]<<" " ;
        ans.push_back(matrix[rowst][i]);
        }
        rowst ++ ;
        for(int j=rowst; j<=rowen && colst<=colen ; j++){
            ans.push_back(matrix[j][colen]);
            //cout<<matrix[j][colen]<<" " ;
        }
        colen -- ;
        for(int i = colen ; i>=colst  && rowst<= rowen   ; i--){
            ans.push_back(matrix[rowen][i]);
            //cout<<matrix[rowen][i]<<" " ;
        }
        rowen-- ; 
        for(int i= rowen; i>=rowst && colst<=colen ; i--){
            ans.push_back(matrix[i][colst]);
            //cout<<matrix[i][colst]<<" " ; 
        }
        colst ++ ;
        
       // cout<<endl ;
       
    }
    return ans ; 
    }
    
};
*/
/*
/// Transpose of matrix 
int main(){
    int n  ;
    cin>>n  ;
    int a[n][n];
    for(int i = 0; i<n ;i++){
        for(int j=0;j<n ; j++){
            cin>>a[i][j];
        }
    }
    int na[n][n] ;  /// in this method we create a new matrix 
    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<n ; j++){
            cout<<a[j][i]<<" " ;
        }
        cout<<endl  ; 
    }
    for(int i = 0; i<n ;i++){
        for(int j=0;j<n ; j++){
            cout<<na[i][j]<<" ";
        }
        cout<<endl ; 
    }
    
    return 0 ;
}


// by  swapping 
int main(){
    int n  ;
    cin>>n  ;
    int a[n][n];
    for(int i = 0; i<n ;i++){
        for(int j=0;j<n ; j++){
            cin>>a[i][j];
        }
    }
    for (int i=0; i<n ; i++){
        for(int j=i+1 ; j<n;j++){
            int temp = a[i][j] ;
            a[i][j] = a[j][i];
            a[j][i]= temp ; 
        }
    }
    for(int i = 0; i<n ;i++){
        for(int j=0;j<n ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl ; 
    }
    return 0 ; 
}*/


/*
 // Matrix multiplication 
 // two matrix are given of order n1xn2 and n2xn3 
 // the output matrix should be order n1xn3 
int main(){
    int n, m , l  ;
    cin>>n>>m>>l  ;
    int mat1[n][m];
    int mat2[m][l] ; 
    int mulmat[n][l];
    for(int i = 0; i<n ;i++){
        for(int j=0;j<m ; j++){
            cin>>mat1[i][j];
        }
    }
    for(int i = 0; i<m ;i++){
        for(int j=0;j<l ; j++){
            cin>>mat2[i][j];
        }
    }
    for(int i = 0; i<n ;i++){
        for(int j=0;j<l; j++){
            int sumofmultiples = 0 ; 
            for(int k = 0 ; k<m ; k++){
                sumofmultiples += (mat1[i][k])*(mat2[k][j]);
            }
            mulmat[i][j] = sumofmultiples ;

        }
    }
    for(int i = 0; i<n ;i++){
        for(int j=0;j<l ; j++){
            cout<<mulmat[i][j]<<" ";
        }
        cout<<endl ; 
    }
    
}   
*/ 

// matrix search 

// brute force approach 
/*int main(){
    int n, m , k  ;
    cin>>n>>m>>k  ; 
    int mat[m][n] ;
    for(int i = 0; i<m ;i++){
        for(int j=0;j<n ; j++){
            cin>>mat[i][j];
        }
    }
    for(int i = 0; i<n ;i++){
        for(int j=0;j<m ; j++){
            if(k == mat[i][j]){
                cout<<1 ; 
                return 0 ; 
            }
        }
    }
    cout<<0 ; 
    return 0 ; 
}
*/
/*
// something wrong in this code 
int main(){
    int n, m , k  ;
    cin>>m>>n>>k  ; 
    int mat[m][n] ;
    for(int i = 0; i<m ;i++){
        for(int j=0;j<n ; j++){
            cin>>mat[i][j];
        }
    }
    int i= m/2 ;
    int j = n/2 ;
    while (i<m && j<n&& i>=0 && j>=0){
        if(k== mat[i][j]){
            cout<<1 ;
            return 0 ; 
        }
        else if (k>mat[i][j]){
            for(int k = i; k<m; k++){
                if(mat[k][j] == k){
                    cout<<1 ;
                }
            }
            for(int k = i; k<n; k++){
                if(mat[i][k] == k){
                    cout<<1 ;
                }
            }
            i = (i+m)/2 ;
            j = (j+n)/2 ;
        }
        else if (k<mat[i][j]) {
            for(int k = 0; k<i; k++){
                if(mat[k][j] == k){
                    cout<<1 ;
                }
            }
            for(int k = 0; k<i; k++){
                if(mat[i][k] == k){
                    cout<<1 ;
                }
            }
            i = i/2 ;
            j = j/2 ;
        }
    }
    cout<<0 ; 
    return 0 ; 

}
*/


/// search in a sorted rows matrix 
/*
int main(){
    int n, m , k  ;
    cin>>m>>n>>k  ; 
    int mat[m][n] ;
    for(int i = 0; i<m ;i++){
        for(int j=0;j<n ; j++){
            cin>>mat[i][j];
        }
    }
    // here we have two starting points (row=0 &col = n-1) or (row=m-1 && col = 0 )
    int i = 0; 
    int j = n-1 ;
    bool found = false ;
    while(i<m && j>=0) {
        if(mat[i][j]== k){
            found = true  ;
            break ; 
            
        }
        else if (k < mat[i][j]){
            j-- ;
        }
        else {
            i++ ;
        }
    }
    if (found){
    cout<<"number is found "; 
    }
    else {
        cout<<"number is not exist ";
    }
    return 0 ; 
}
*/

