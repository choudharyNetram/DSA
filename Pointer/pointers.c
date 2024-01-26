# include<stdio.h>
/*void square(int n );
void _square(int *n);

int main(){
    int n = 4;
    square(n);
    printf("number = %d\n",n ); 

    int number  = 4;
    _square(&number);
    printf("_number =  %d", number);
    return 0;
}

void square( int n ){
    n = n * n ;
    printf("square = %d\n", n);

}
void _square(int *n){
    *n = (*n)*(*n);    
    // we change the value of address but address remain same,   hmne ab value ko hi change kr diya
    printf("_square = %d", *n); // here we change the value of number in his address 
}
*/
void swap(int* x , int* y );

int main(){
    int x = 3; int y = 4 ;
    
    printf("x = %d and y = %d", x , y);    // if we call the swap function  than the values are interchange in address , 
    // if we don't call this function the value doesn't interchange in 
    swap(&x, &y);
    return 0;

}
void swap(int* x , int* y ){  // x,y =  here we take input as a pointer or address
    int t = *x ;
    *x = *y;
    *y = t;
    printf("x = %d and y =%d ", *x , *y);
}

