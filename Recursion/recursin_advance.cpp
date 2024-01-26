#include<iostream>
using  namespace std ;

/*
///  rat in a maze 
// count total path in a maze move from (0,0) to (m,n)
int count  = 0 ;
int countpath(int i , int j , int m , int n ){
    if(i==m || j == n){
        return 0 ;
    }
    if((i == m-1) && (j == n-1)){
        return 1; 
    }
    int downpath = countpath(i+1, j, m , n);
    int rightpath = countpath(i, j+1, m, n);
    return downpath+rightpath ;
}

int main(){
    int i = 0, j =0 ,m = 4,n = 3 ;
    cout<<countpath( i, j , m, n);
    return 0 ;   
}
*/

// how many ways we can place tiles of size (1 X m) into a floor of (nXm)
// my method --->
/*
int placetiles(int i , int m , int n){
    if(i > n){
        return 0 ;
    }
    if(i==n){
        return 1 ;
    }
    int placehori = placetiles(i+1, m,n);
    int placevart =  placetiles(i+m, m , n);
    //cout<<placehori<<endl ;
    //cout<<placevart<<endl; 

    return (placehori + placevart) ;
    
}
int main(){
    int i = 0 , m = 4 , n = 2 ;
    cout<<placetiles(i, m , n);
    return 0 ;
}*/

// Method 2 
/*
int placetiles(int n, int m){
    if(n== m){
        return 2 ;
    }
    if(n<m){
        return 1; 
    }
    // place vertical  
    int placevert =  placetiles(n-m,m );
    // place horizontal 
    int placehort = placetiles(n-1, m);
    return placevert+ placehort ;

}
int main(){
    int  m = 2 , n = 4 ;
    cout<<placetiles(n, m);
    return 0 ;
}*/
/*
// find the number of ways in  which you can invite people to your  party single or in pair 
int callguests(int n){
    if(n==1 ){
        return 1;
    }
    if(n==2){
        return 2 ;
    }
    // recursive method  ==> call(n) =  (if single than call(n-1)) + (if pair than (n-1)*caLL(n-2)
    int single = callguests(n-1);
    int ifPair = (n-1)*(callguests(n-2));
    return single + ifPair ;
}
 
int main(){
    int n =  4 ;
    cout<<callguests(n);
    return 0 ;
}
*/

