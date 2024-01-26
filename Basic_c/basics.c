# include<stdio.h>
// reverse the array 
/*int main(){
    int arr[] = {1, 2, 3 ,4,5};
    int n = 5;
    for(int i = 0; i< n/2; i++){
        int t = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = t;


    }
    for (int i=0; i<n; i++){
        printf("%d\n",arr[i]);

    }
    return 0;



}
*/
/*
int main(){
    int arr[2][10];
    for(int i = 0; i<2; i++){
        for(int j=0; j<10; j++){
            arr[i][j] = (i+1)*(j+1);
            

        }

    }
    for (int i=0; i<10; i++){
        printf("%d\n",arr[i][0] );

    }
    return 0 ;

}
*/

int main(){
    int arr[5];
    int *ptr = &arr[0] ;
    for(int i = 0 ; i< 5; i++){
        scanf("%d" ,(ptr+i));
    }
    for(int i = 0 ; i< 5; i++){
       printf("%d" ,*(ptr+i));
    } 
    return 0; 
}

