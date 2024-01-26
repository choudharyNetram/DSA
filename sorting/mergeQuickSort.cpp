#include<iostream>
using namespace std ;

// this sorting method on devide and conquer method 
// first we divide  array in single elements and than merge them 

// it has two method --> 1. create new array and copy values 
// 2. use indexs 

// this below code is for the create two array 
// basics rule of this code is that first we take array we divide into part , the recursion 
// us the sorted array and than we merge those two sorted arrays 

void merge(int *arr, int s , int e){ // here we are passing array by reference  because we want to change  the existing array
    int mid = (s+e)/2 ;
    int  len1 = mid-s+1 ;
    int len2 = e- mid ;
    int *first = new int[len1];
    int *second = new int[len2];
    // copy values 
    int k = s ;  // here k is the main array index ;
    for(int i = 0 ; i< len1 ; i++){
        first[i] = arr[k];
        k++ ; 
    }

    k = mid+1 ;
    for(int i = 0 ; i< len2; i++){
        second[i] = arr[k];
        k++ ;
    }
    int index1  = 0 ;
    int index2  = 0  ;
    k = s ;
    int count = 0  ;
    while( index1 < len1 &&  index2<len2){
        if(first[index1]<second[index2]){
            arr[k] = first[index1]; // we can write whole condition  by this arr[k++]= first[index1++]
            k++ ;
            index1++ ;
        }
        else  {
            arr[k] = second[index2];  
            k++ ;
            count++ ; 
            index2++ ;
        }

    }
    while(index1 < len1){
        arr[k++]= first[index1++];
        count++ ;

    }
    while(index2 < len2){
        arr[k++]= second[index2++];
    }
    cout<<count<<endl; 
    delete []first ;
    delete []second ;
}

void mergeSort(int *arr,  int s , int e){
    // base case 
    if(s>=e){
        return ;
    }
    int mid = (s+e)/2;

    // sort the left part 
    mergeSort(arr, s, mid);
    // sort the right part 
    mergeSort(arr, mid+1 , e);
     
    // merge them 
    merge(arr, s, e);
    
}

int main(){
    
    //int arr[5]= {1,2,3,4,5};
    int  n ;
    cin>>n ;  
    int arr[n] ;

    for(int i = 0 ; i< n; i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n -1) ; // s =  start , e = end ;
    for(int i = 0 ; i< n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl ;
    return 0 ;
}

/// read about inversion count from gfg 



/////// Quick sort 

// method of this sorting:- first pick one element and
// put it in the right place and all the left elements are samll than   it and right elements are greater than it
//  ex. {3,5,1,8,2}
// like in this example right position of 3 is {1, 5, 3 , 8, 2} --> {1, 2, 3, 8, 5}
/*
int partition( int *arr, int s , int e){
    int pivot = arr[s];
    int count  =  0 ;
    //  findinng the  right place for pivot 
    for( int i =  s+1  ; i<= e ; i++){
        if(arr[i]< pivot){
            count++ ; 
        }
    }
    // place pivot at right position 
    int pivotIndex = count+ s ; 
    swap(arr[s], arr[pivotIndex]) ;
    // now we have to check that is all left elements are small and all right elements are greater than pivot 
    int i = s , j = e ; 
    while(i< pivotIndex && j > pivotIndex){
        while(arr [i]< pivot){
            i++ ;
        }
         while(arr [j] > pivot){
            j-- ;
        }
        if( i< pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
        
    }
    return pivotIndex ;
}

void quickSort(int *arr, int s, int e){
    /// base case 
    if(s>= e){
        return ; 
    }
    int p = partition(arr, s,  e);

    // left part ko sort kro 
    quickSort(arr, s, p-1);
    // right part ko sort  kro 
    quickSort(arr, p+1 ,  e);

    
}
int main(){
    int n = 5 ;
    int arr[n] = { 8,2,5,3,1} ;
    quickSort(arr, 0, n-1);
    for(int i = 0 ; i< n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;  
    return 0; 
}
*/

////******** read from gfg why quick sort is prefare than merge sort and in linked list why merge sort is preferred 
// this upper article in the gfg quick sort algorithm 

// read about in-place and stable algorithms 
//    https://www.geeksforgeeks.org/in-place-algorithm/ 
//  https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/
/* in-place = An in-place algorithm is an algorithm that does not need an extra space and produces an output 
in the same memory that contains the data by transforming the input ‘in-place’. However, a small constant extra 
space used for variables is allowed.*/
