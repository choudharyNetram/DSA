/*#include<stdio.h>

int main(){
    float arr[] = {2.0, 3.0 , 4.0} ; 
    printf("%f\n", *arr); // by this we get 0th index of the array arr , 
    // because the name of the array is a pointer that points on 0th index of array 
    
    int age = 22; 
    int *ptr = &age ; 
    printf("%u\n", ptr);
    ptr++;
    printf("%u", ptr);
    return 0;
}
/*
int main(){
    int aadhar[5];
    int *ptr = aadhar ;  //int *ptr = &aadhar[0];
    for (int i=0; i<=3; i++) {
        printf("%d index ",  i);
        scanf("%d", (ptr+i));

    }
   for (int i= 0; i<=3; i++){
       printf("number is %d\n", *(ptr+i));
   }
   return 0;

}*/
/*
int  printodd(int arr[] , int n );

int main(){
    int arr[] = {1, 2, 3, 4 ,5, 6};
    printodd(arr,6);
    return 0;

}   

int  printodd(int arr[] , int n){
    for(int i=0; i<n; i++){
        if(arr[i] % 2 != 0){
            printf("%d\n", arr[i]);
        }
    }
    
}*/


#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int k[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &k[i][j]);
    }}
    int vis[n + 1];
    int count = 1;
    int i = 1,l=0;
    for(int u = 1 ; u<=n ;u++){
        vis[u] = 0 ; 
    }

     while (l == 0){
       l=1;
      for (int j = 1; j <= n; j++) {
        if (k[i][j] == 1) {
          vis[j] = 1;
        }
      }
      for (int j = 1; j <= n; j++) {
        if (vis[j] == 0) {
          i = j;
          l = 0;
          count += 1 ;
           break; 
        }
      }
    } 
  printf("%d",count);

    return 0;
  }

