#include<iostream>
using namespace std ;

// selection sort 
/*void selectionsort(int array[],int n ){
    int mini = 0 ; 
    int t ;
    for(int i=0; i<n-1;i++ ){
        for(int j=i+1; j<n; j++){
            if(array[j]< array[mini]){
                mini = j;

                
            }
        }
        t = array[i] ;
        array[i] = array[mini] ;
        array[mini]= t ;
    }
    for(int i = 0; i<n; i++){
        cout<<array[i]<<" ";
    }
    return ; 
    

}


int main(){
    int n ;
    cin>>n ; 
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    selectionsort(array, n);
    
    

}
*/

// bubble sort 
/*
void bubblesort(int arr[], int n){
    for(int i = 0; i<n; i++){
        for(int j= 0; i<n-i; j++){
        if(arr[j+1]<arr[j]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp ;
        }
    }
    }
    for(int i=0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return  ; 


}

int main (){
    int n; 
    cin>>n;
    int arr[n]  ;
    for(int i=0; i<n; i++){
        cin>>arr[i] ; 
    }
    bubblesort(arr, n) ;
    return 0 ; 
}
*/
/*
int main (){
    int n; 
    cin>>n;
    int arr[n]  ;
    for(int i=0; i<n; i++){
        cin>>arr[i] ; 
    }
    

    for(int i = 0; i<n-1; i++){
        for(int j= 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                //cout<<arr[i]<<" ";
                arr[j] = arr[j+1];
                arr[j+1] = temp ;
            }
        }
    }
    for(int i=0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0 ; 
}
*/


//insertion sort 
// in the there are two parts first is sorted one and other is unsorted one. we pick first element from unsorted one then 
// putting it on its correct position in sorted array 
/*
int main(){
    int n ;
    cin>>n ;
    int arr[n];
    for(int i=0 ; i<n; i++) {
        cin>>arr[i];
    }
    
    for(int i= 1; i<n; i++){
        int current = arr[i];
        int j= i-1 ;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];

            j-- ; 
        }
        arr[j+1]= current ;
    }
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" " ;
    }
    return 0 ;
}

*/




