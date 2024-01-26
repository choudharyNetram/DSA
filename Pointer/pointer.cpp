#include<iostream>
using namespace std ;
/*int  main(){
    int a  = 10 ;
    int * aptr = &a; 
    
    //cout<<aptr<<endl ;
    cout<<*aptr<<endl ;
    *aptr = 20 ; 
    cout<<*aptr<<endl ;
    return 0 ; 
}


// arthimetic operation in pointers 
// the name of the array store the address of 0th elements
//arrray is a pointer  

int main(){
    int arr[] = {1, 3 , 5} ;
    cout<<*arr<<endl ; 
    int *aptr = arr ; 
    for(int i = 0 ; i<3 ; i++){
        cout<<*aptr<<endl ;
        aptr++ ; 
    }
    // arr is constant value of address , we can't modify this 
    // arr++ --> illegal 
    // arr is a indexing pointer 
    for(int i = 0 ; i<3; i++){
        cout<<*(arr+i)<<endl ; 
        
    }
    
    return 0; 
}
*/
// pointer to pointer 
/*
int main(){
    int a= 10 ; 
    int * aptr = &a ;
    int  **aptrptr = &aptr ;
    cout<<*aptrptr <<endl ;
    cout<<**aptrptr<<endl ; 
    // passing pointer to function 
    void increment(int  a){
        a++ ;
    }

    return 0 ;
}

    
/*
int main(){
    int  a= 10 ;
    increment(a);
    cout<<a<<endl ; 
    return 0 ; 
}



// call by reference 
/*
void swap(int * a, int*b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
int main(){
    int a = 10; 
    int b = 20 ;
    int*aptr = &a ;
    int *bptr = &b; 
    swap(aptr , bptr) ;
    cout<<a<<" " <<b; 
    return 0 ;
}*/