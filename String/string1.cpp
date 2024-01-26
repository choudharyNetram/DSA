/// what is the string:- 1 dimensional char array 
//

// char array:- 
// how to take a string input  
// char name[20];
// cin>>name ; 
// if we give only 6 element string but we intialize with 20 element size, 
// than from index 7 to 19, NULL character exist 
// NULL  character :-  ascii value is 0 
// we use null char as a terminator
// we can know null char that at this index string is finished 

// if we give a space, tab and enter in string input than cin only take before space,tab and enter 
//  space( ) ,,, tab(\t) ,, enter(\n)
// Null character :- nullChar = '\0' 

#include<iostream>
using namespace std ; 


// function of length of string 
int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}

// how to reverse a string or char arrray 
void reverse(char name[], int n) {
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name[s++], name[e--]);
    }
}

char toLowerCase(char ch) {
    if(ch >='a' && ch <='z')
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
// checking a string  is palindrome 

bool checkPalindrome(char a[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(toLowerCase( a[s] ) != toLowerCase( a[e] ) )
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}


int main(){
    char name[20] ;
    //cin>>name ;
    //cout<<name ; 
    cin>>name ;
    //name[2] = '\0' ;
    cout<<name<<endl ; 
    string str ;
    cin>>str ; 
    cout<<str<<endl ; 
    return 0 ; 
}





//// how to take a line in an input 
// cin.getline(str, length)
/* example= 
string str ; 
cin.getline(str, 5) ; 
*/

// what is custom delimeter 
//    https://www.geeksforgeeks.org/cpp-string-to-vector-using-delimiter/


// we can compare string by inbuilt function
// strcomp(s1,s2)

// we can copy a string into another string
// strcpy(dest, src) 
// source string copied into destiny string


// we have also inbuilt  function for find a part string in a string 
/// like in s1 = "abaabcabdbab" ; s2= "abc" 
// we can find string s2 in string s1 direct by find function and we can erase also 

/// https://cplusplus.com/reference/string/string/


class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()!=0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

