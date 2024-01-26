#include <iostream>
using namespace std;
// reverse a string using recursion 
// Method  first 
/*
string revstr(string s, int i , int n){
    if(i>n/2){
        return s ;
    }
    int temp = s[i];
    s[i]=s[n-i-1];
    s[n-i-1]= temp ; 
    return revstr(s, i+1, n);
}
int main(){
    string s = "binod";
    
    int n = 5 ;
    int i = 0 ;
    //cout<<s ;
    cout<<revstr(s, i, n);
    return 0 ;
}
*/
// method second 
/*
void rev(string s){
    if(s.length()==0){  // base case
        return ;
    }
    string restOfString = s.substr(1); // this is the string starting from index 1 to n-1
    rev(restOfString) ;
    cout<<s[0];

} 
int main(){
    string s = "komal";
    rev(s);
    return 0  ;
}
*/
// replace pi by 3.14 
/*
void replacepi(string s){
    if(s.length() == 0){
        return ;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<3.14 ;
        replacepi(s.substr(2));
    }
    else{cout<<s[0];
    replacepi(s.substr(1));}
}
int main(){
    string s = "netramppipii";
    replacepi(s);
    return 0 ;
}
*/


// tower of hanoi using recursion 
/*
Method of this problem :- first we move n-1 disks to source to helper 
and than move largest disk from source to destiny and than move n-1 disks 
from helper to destiny 

void towerofhanoi(int n, char src, char dest , char helper ){
    if(n==0){
        return ;
    }
    towerofhanoi(n-1, src, helper, dest);
    cout<<"move from"<<" "<<src<<" "<<"to"<<" "<<dest<<" "<<endl ;
    towerofhanoi(n-1, helper, dest, src);
}
int main(){
    int n = 3 ;
    towerofhanoi(n, 's', 'd', 'h');
    return 0; 
}

*/

// finding x^n usnig logn stack 
//  basic idea in  this  question is that write  x^n = x^n/2 * x^n/2
/*
int calpower(int  x, int n){
    if(n == 0){
        return 1  ;
    }
    if(x==0 || x==1){
        return x ;
    }
    if(n%2==0){
        return calpower(x, n/2)*calpower(x, n/2);
    }
    else{
        return calpower(x, n/2)*calpower(x, n/2)*x;
    }

}
int main(){
    int  n = 2;
    int x=  0;
    cout<<calpower(x, n);
    return 0  ;
}
*/
/*
// move all x to the end of the string 
string new_str = "" ;
string movex(string s , int idx, int count){
    if(idx == s.length()){
        for(int i = 0; i<count; i++){
            new_str += 'x';
        }
        return new_str ;
    }

    if(s[idx]=='x'){
        count++ ;
    }
    else{
        new_str =  new_str+s[idx];
    }
    return movex(s, idx+1, count);
}
int main(){
    string s = "netramxjatxkomalx";
    int idx = 0 ;
    int count = 0 ;
    cout<<movex(s, idx,count);
    return 0 ;
}*/


// remove all duplicates from a string
/*
void removedup(string s){
    if(s.length()==0){
        return ;
    }
    if(s[0]==s[1]){
        s = s.substr(1);
    }
    else{
        cout<<s[0];
        s = s.substr(1) ;
    }
    removedup(s);
    
    
}
int main(){
    string s = "aaaaabbbcccddde";
    removedup(s);
    return 0 ;
}
*/
/*
// better method for removing duplicate from a string
string removedup(string s,int idx, int map[26], string new_str){
    if(s.length()==idx){
        return new_str;
    }
    if(map[s[idx]-'a']==true){
        return removedup(s,idx+1, map,new_str) ;
    }
    else{
        new_str += s[idx];
        map[s[idx]-'a']=true ;
        return removedup(s,idx+1, map,new_str) ;
    }
}
int main(){
    string s = "netramjatkomal";
    int map[26];
    for(int i = 0 ; i<26; i++){
        map[i]= false; 
    }
    int idx = 0 ;
    string new_str = "";
    cout<<removedup(s, idx, map, new_str);
    return 0 ;
}

*/


// print all the subsequence of a string
/*important learning from this question--> if we pass new_string 
in the function and we update this then we can print new_string many times

void printsubseq(string s , int idx, string newstr){
    if(idx == s.length()){
        cout<<newstr<<endl ;
        return ;
    }
    char currchar = s[idx];
    
    printsubseq(s, idx+1, newstr+currchar);
    printsubseq(s, idx+1, newstr);
}
int main(){
    string s = "abc";
    string newstr = "";
    int idx = 0 ;
    printsubseq(s, idx, newstr);
    return 0 ;  
}
*/
// print all the uniqe subsequence of a string 
// here we use a data structure called hashset 
// in the ds this only contain unique element
/*
#include <unordered_set>

void printsubseq(string s , int idx, string newstr, unordered_set<string> hashset){
    if(idx == s.length()){
        if(hashset.find(newstr)==hashset.end()){// if hashset not contain newstr
        // then we don't print and else if hashset not contain newstr than we print newstr and insert in hashset 
            cout<<newstr ;
            hashset.insert(newstr);
            return ;
        }
        else{
            return ;
        }
        cout<<newstr<<endl ;
        return ;
    }
    char currchar = s[idx];
    
    printsubseq(s, idx+1, newstr+currchar);
    printsubseq(s, idx+1, newstr);
}
int main(){
    string s = "abc";
    string newstr = "";
    int idx = 0 ;
    unordered_set<string> hashset = new unordered_set<>();
    printsubseq(s, idx, newstr);
    return 0 ;  
}
*/

// keypad lecture 
/*
string[] keypad = {".", "abc", "def", "ghi", "jkl","mno", "pqrs", "tu","vwx","yz"};
void printcomb(string str,int idx, string combination ){

    char currChar = str[idx];
    string mapping = keypad[currChar - '0'];
    for(int i = 0; i<mapping.length() ; i++){
        printcomb(str, idx+1 , combination+mapping.str[i])
    }
}
*/

