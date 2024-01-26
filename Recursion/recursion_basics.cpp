#include<iostream>
using namespace std; 
// sum by using recursion
/*
/// write the recursive tree, it is the most important concept in this chapter 
int sum(int n){
    if(n==0){
        return 0  ;
    }
    int prevsum = sum(n-1);
    return n+prevsum;
}
int main(){
    int n ;
    cin>>n ;
    cout<<sum(n);
    return 0 ; 
}
*/
// calculating the n raised to the power p 
/*
int pow(int n , int p){
    if(p==0){
        return 1 ;
    }
    int prevmul = pow(n, p-1);
    return n*prevmul ;

}

int main(){
    int n, p  ; 
    cin>>n>>p ;
    cout<<pow(n, p);
    return 0 ;
}
*/

// factorial of a number n 
/*int fac(int n){
    if (n==1 || n==0){
        return 1 ;
    }
    int prefac = fac(n-1);
    return n*prefac ;
}
int main(){
    int n ; 
    cin>>n ;
    cout<<fac(n);
    return 0 ;
}
*/
// finding the nth fiboonacci number
// ----> the fibbonacci number start from  the 0th position 
// means that 0th fibbonacci number is zero and first is 1 
// fibnum(0)== 0, fibnum(1)==1 
/* 
int fibnum(int n){
    if(n==1 || n==0){
        return n;
    }
    return fibnum(n-1)+fibnum(n-2);
}
int main(){
    int n ; 
    cin>>n ;
    cout<<fibnum(n);
    return 0 ;
}
*/

// check if an array is sorted or not 
/*
bool checksorted(int arr[],int n){
    if(n==1){
        return 1 ;
    }
    bool restArray = checksorted(arr+1,n-1);
    return ((arr[0]<arr[1]) && restArray);
}
int main(){
    int n = 5;
    int arr[n] = {1,2,8,4,5};
    cout<<checksorted(arr, n);
    return 0;

}



// printing number in increasing order and decreasing order till n 
int dec_od(int n){
    if(n == 0){
        return 1 ;
    }
    cout<<n<<endl ;
    return dec_od(n-1);
}
int main(){
    int n ; 
    cin>>n ;
    dec_od(n);
    return 0 ;
}

//*******_*********
// 
void inc_od(int n){
     
    if(n == 0){
        return ;
    }
    inc_od(n-1);    // in the decreasing order we first call the function and then print 
    cout<<n<<endl ;

}
int main(){
    int n ; 
    cin>>n ;
    inc_od(n);
    return 0 ;
}
*/

// finding the first and last occurance of a number  in a array 
/*
int findFirstOcc(int arr[], int n , int i,  int k){
    if(arr[i]==k){
        return i ;
    }
    return findFirstOcc(arr, n , i+1 , k);
}
int main(){
    int n = 9;
    int key = 2 ;
    int i = 0 ;
    int arr[n]= {1,3,2,2,2,2,4,5,2};
    cout<<findFirstOcc(arr, n, i, key );
    return 0 ;
}
*/
/*
int lastOcc(int arr[], int n,  int i , int k ){
if(arr[i]==k){
        return i ;
    }
    return lastOcc(arr, n , i-1 , k);
}
int main(){
    int n = 9;
    int key = 2 ;
    int i = 8 ;
    int arr[n]= {1,3,2,2,7,2,2,4,5};
    cout<<lastOcc(arr, n, i, key );
    return 0 ;
}
*/
//method second
/*
int first = -1;
int last = -1 ; 
void findoccur(string s, int idx, char character){
    if(s.length() == idx){
        cout<<first<<endl;
        cout<<last<<endl;
        return ;
    }
    if(character==s[idx]){
        if(first == -1){
            first = idx ;
            cout<<first ;
        }
        else{
            last = idx ;
        }
    }
    findoccur(s, idx+1, character);
    
}
int main(){
    string s = "asdjaaaa";
    int idx = 0;
    char cha= 'a';
    findoccur(s,idx , cha);
    return 0;
}
*/
/*
/// recursive method to check that array is sorted or not 

bool isSorted(int arr[], int size) {

    //base case
    if(size == 0 || size == 1 ){
        return true;
    }

    if(arr[0] > arr[1])
        return false;
    else {
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }

}

/// best thing to learn  in upper question is that if we passing (arr+1) that means that array will excuting from index 1 to size-1 
//// the name of the array is the pointer of 0th index 



/// sum of the array by recursion 

int getSum(int *arr, int size) {

    //base case
    if(size == 0) {
        return 0;
    }
    if(size == 1 )
    {
        return arr[0];
    }

    int remainingPart = getSum(arr+1, size-1);
    int sum = arr[0] + remainingPart;
    return sum;
}

/// linerar search by recursion
void print(int arr[], int n) {
    cout << "Size of array is " << n << endl;

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

}

bool linearSearch(int arr[], int size, int k ) {
    print(arr,size);
    //base case
    if(size == 0) 
        return false;

    if(arr[0] == k) {
        return true;
    }
    else {
        bool remainingPart = linearSearch(arr+1, size-1, k );
        return remainingPart;
    }
}

/// binary  search using  recursion 
void print(int arr[], int s, int e) {

    for(int i=s; i<=e; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

bool binarySearch(int *arr, int s, int e , int k ) {

    //base case

    //element not found
    if(s>e)
        return false;

    int mid = s + (e-s)/2;

    //element found
    if(arr[mid] == k)
        return true;

    if(arr[mid] < k) {
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}


// revese  a string using recursion 

void reverse(string& str, int i, int j ) {

    cout << "call recieved for " << str << endl;

    //base case
    if(i>j)
        return ;

    swap(str[i], str[j]);
    i++;
    j--;

    //Recursive call
    reverse(str,i,j);

}
*/

/// power of (a**b) 

int power(int a, int b){
    if(b==0){
        return 1 ; 
    }

    return a*power(a, b-1)  ;

}
// the time complexity of above question is O(n)

/// better solution 
// if b is even =  (a**(b/2))*(a**(b/2))
// else b is odd = (a**(b/2))*(a**(b/2))*a

int Power(int a , int b){
    if(b==0){
        return 1 ; 
    }
    if(b==1){
        return a ; 
    }
    if(b%2 == 0){
        return Power(a, b/2)*Power(a, b/2) ; 

    }
    else {
        return Power(a, b/2)*Power(a, b/2)*a ; 
    }
}
int main(){
    int a = 3 ;
    int b = 4;
    cout<<power(a, b)<<endl ;
    cout<<Power(a, b)<<endl ;
    
    return 0 ;
}

// bubble sort using recursion 

void sortArray(int *arr, int n) {

    //base case - already sorted
    if(n == 0 || n == 1) {
        return ;
    }

    //1 case sovle karlia - largest element ko end me rakh dega
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    //Recursive Call
    sortArray(arr, n-1);

}


