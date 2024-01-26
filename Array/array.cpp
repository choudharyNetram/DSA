/*# include<iostream>
# include<climits>
using namespace std ; 

// here we find max and min value in a array 
//for instalization we use minimum value of number in c++ 
int main()
{
int max_value = INT_MIN;
int min_value = INT_MAX ;
int array[5] = { 5,44,6,7,8};
for (int i = 0; i<5; i++ ){
    max_value = max(max_value, array[i]);
    min_value = min(min_value, array[i]);

} 
cout<<max_value<<" " ;
cout<<min_value<<endl ;
return 0 ;
}
*/


// binary search 
#include <iostream>
using namespace std; 
int binary_search(int array[], int n, int key ){
    int s = 0 ;
    int e = n ;
    int mid ; 
    while(s<=e){
        mid = (s+e)/2 ;
        if(array[mid] == key){
            return mid ;
        }
        else if (key> array[mid]){
            s = mid+1 ;

        }
        else {
            e = mid-1 ;

        }
    }
    
    return -1;
    
} 
int main(){
    cout<<"enter n" ;
    int n ; 
    cin>>n ;
    int array[n];
    for (int i= 0; i<n ; i++){
        cin>>array[i];

    }
    int key ;
    cin>>key ; 
    cout<<binary_search(array, n ,key) ;
    return 0 ; 


}