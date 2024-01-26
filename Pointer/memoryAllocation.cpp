// when we use stack memory it is call static memory and if we use dynamic memory 
// heap momory it is called dynamic memory 
// the stack memory is alloted to array 

/* if we do like this 
cin>>n ; arr[n] --> then the size of the array decide at run time
upper practice is not good because many times the code can't be compiled 


arr[10000] --> then we know the size of the array at compile time 
this is a good because if we give the size at run time then the we can 
take stack is big memory or we can increase the size of the stack memory

the memory in stack is less and in heap is very large 
*/



/*
we can make variable size array by heap memory 
if we want to do anything in heap than we should use 'new' keyword
example:- new char ; */
// dynamic memory allocation 

//int *ptr = new arr[5] // here the memory of array is stored in heap memory(5*4 = 20)
// the ptr pointer stored in stack memory(8 byte)
// in dynamic array there are no need to write array name 
// we only give address of the array 


#include<iostream>
using namespace std ;
/*
int main(){
    int n ;
    cin>>n ;
    // variable size arrray 
    int *arr = new int[n];
    for(int  i = 0 ; i< n ; i++){
        cin>>arr[i];
    }
    int  ans  = arr[2];
    cout<<ans<<endl; 
    return 0; 
}
*/
// case 1 
/* while(true){
    int i = 8 ;
}

case 2 
 while (true){
    int *ptr = new int ; 
}

in case 1 the integer memory is allocated in the stack , when one loop ends than stack become empty
so in case 1 every time  this loop takes 4 byte memory 

In case 2: 
ptr taking memory in stack , but int taking in the heap ;
ptr memory become empty, but heap memory didn't become empty 
heap me memory lete ja rhe h 


static memory:- memory automatically release ho jati h 
dynamic memory:- memory  automatically realse nhi hoti , manually  krni  pdti h 

method of deleting of memory in dynamic memory allocation 
use 'delete' key word 
single element deletion 
 int *i = new int ; 

 delete i ; 

array deletion 
int *arr = new int[50];
delete []arr ; 
*/

// 2-D array using dynamic memory allocation 
// method --> first we creaste a array arr of size of rows , in this array arr we create a column size array in each rows of pointers 
// arr me m(_,_,_,_) rows h , every row me ek pointer h , every pointer me ek array h arr[i] column size ka 
//2022-10-04.png
/*
int main(){
    int row , col ;
    cin>>row>>col ;
    // creating n  rows 
    int** arr =  new int*[row];
    /// filling all rows with columns  
    for(int i = 0 ;i< row;  i++){
        arr[i] = new int[col];
    }

    // taking input 
    for (int i = 0 ; i< row ; i++){
        for( int  j= 0 ; j< col ; j++){
            cin>>arr[i][j];
        }
    }

    // printing outpout 
    for (int i = 0 ; i< row ; i++){
        for( int  j= 0 ; j< col ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl; 
    }
    // releasing array 
    /////// remeber every time you use heap memory than deleting it is necessary 

    for ( int  i = 0 ; i< row ; i++){
        delete [] arr[i] ; 
    }
    delete []arr ;
    return 0; 
}
*/
// jaggered array -->  array which have different size of columns 
