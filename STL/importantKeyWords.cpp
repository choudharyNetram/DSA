#include<iostream>
using namespace std ;
// what is a macro 
// macro:- a piece of code in  program that is replaced by the value of macro 
// one benefit of macro is that we don't need extra memory of making a variable like  pi 
// PI is not a varible ,we can't change it 
// from below read about macro 
////https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/ 
//  
/*
 #define PI 3.14 
int main(){
    //double pi = 3.14 ;
    int r = 5 ;
    double area = PI* r*r ;
    cout<<"Area is "<<area<<endl;
    return 0 ;
}
*/
/*
/// Global variable --> is a variable that we can use this value in every part of the code 

// example in lower line 
int score = 1 ;
void a( int & i){
    cout<<i<<endl ; 
    cout<<"score in a "<<i <<endl; 
}

void b( int & i){
    cout<<"score in b"<<i <<endl;
}
int main(){
    int i = 5 ;
    cout<<"score in main "<<i <<endl;
    a(i);
    b(i); // but every function can change the value of global function , that's  why this is not a good practise 
    {
        int i = 2 ;
        cout<<i<<endl; /// in this small block value of i is 2 
    }
    cout<<i<<endl;  // here the value of i is 5 ;

    // but if we write small block like this 
    {
        i = 2 ;
        cout<<i<<endl;
    }
    cout<<i<<endl;  // here the value of i is 2 ;
    return 0 ;
}*/


// Inline function--> the way of reduce the function calls overhead 
/// if we pass varible by value than some copy of elements automatically made 
// if we pass by value than alag se memory nhi bnti 
// if we pass the value by reference than no new memory made ;
// we save memory by passing by reference 
/*
void  getMax(int &a , int &b){
    a++ ; 
    b++ ;
    cout<<a<<" " <<b<<endl; 
}
int main(){
    int a = 1 ; 
    int b = 2 ;
    getMax(a, b);
    cout<<a<<" "<<b<<endl; // if we pass by reference than the value of a and b are changed 
    return 0; 
}
*/
// what is the use of the inline function 
// inline funtion directly return ko uta kr jha bhi funtion call kr rhe h wha dal dega 
// like in the below example ,, jha pe bhi getMax function likha h wha pe getMax funtion nhi wha pr getMax funtion ka output h 
// benefit of this  funtion is that , here are no overhead function , and no extra memory uses 

// inline funtion is only used for one line funtions , or may be tow line , not for greater than 3 
/*inline int getMax(int &a , int &b){
    return (a>b)? a:b ; 
    
}

// 
int main(){
    int a = 1 ; 
    int b = 2 ;
    cout<<getMax(a, b)<<endl;
    a = a+2 ;
    b = b +1 ;
    cout<<getMax(a, b)<<endl;
    return 0; 
}
*/



// Default Aruguments 

/* if we want to any argument optional than we can use default argument 

*/ 
// this method is working for left only when right is default 
// if we want to use defalut value on left than right value must be default 
/*
void print(int arr[],int start = 0, int n= 5){
    for(int i = start ; i< n ; i++){
        cout<<arr[i]<<endl; 
    }
    cout<<endl ;
}

int main(){
    int n = 5;
    int arr[n] = {2,3,4,6,7} ; 
    int start = 2; 
    print(arr, start , n) ;
    return 0 ; 
}


// read about constant variables 
*/