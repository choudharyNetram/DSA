#include<iostream> 
using namespace std;
/*
int main(){
    char arr[100] = "apple";
    int i = 0 ; 
    while (arr[i] != '\0' ){
        cout<<arr[i]<<endl ; 
        i++ ;
    }
    return 0 ; 
}


// input- output in array
int main(){
    char arr[100];
    cin>>arr ;
    cout<< arr ;
    return 0 ; 
}
*/
 /// check palindrome 
/*
int main(){
    int n ;
    cin>>n ;
    char arr[n+1] ;
    cin>>arr ;
    int i = 0 ;
    bool flag = 1 ;  
    while(i<n/2){
        if (arr[i]!=arr[n-1-i]){
            flag = 0;
            break ; 
        }
        i++ ;
    }
    if (flag){
        cout<<" the word is palindrome";
    }
    else{
        cout<<"the word is not palindrome";
    }
    return 0 ;
}
*/
/*
// largest word in a sentence 
int main(){
    int n ; 
    cin>>n ;
    cin.ignore();
    char arr[n+1] ;
    cin.getline(arr, n) ;
    cin.ignore();
    
    int maxlen = 0 ;
    int currlen = 0 ; 
    int i = 0 ;
    int st = 0 ; 
    int maxst = 0 ; 
    while(1){
        if(arr[i] = '\0'||arr[i]== ' '){
            if(currlen>maxlen){
                maxlen = currlen ; 
                maxst = st ; 
            }
            currlen = 0 ;
            st = i+1 ;  
        }
        else {
            currlen ++ ; 
        }

        if(arr[i] = '\0'){
            break ;
        }
        
        i++ ; 
    }
    cout << maxlen ; 
    for (int i = maxst ; i<maxlen+maxst ; i++){
        cout<<arr[i] ;
    }
    return 0 ;    
}
// above code is not working 
*/