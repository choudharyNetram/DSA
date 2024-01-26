// hashmaps: most useful data structure 
// its have best time-complexity (insertation, deletion, search)
// using hashtable we can do insertion, deletion, searching in O(1) time 
// map: O(logn)
// unordered_map: O(1)

#include<iostream> 
using namespace std ; 
#include<map> 
#include<unordered_map> 
/*
int main(){
    // creation 
    unordered_map<string,int> m ; 
    // insertion 
    pair<string, int> p = make_pair("Jaat",1);
    pair<string,int> q = make_pair("Ghosliya" , 2) ;
    m.insert(p) ;
    m.insert(q) ;
    m["Netram"] = 3 ; 
    cout<<m["Jaat"]<<endl ;  
    cout<<m.at("Ghosliya")<<endl ; 
    // in  m.at("") and m[""] there is little difference 
    // if we access a unknownkey by m.at("") then an error will through 
    // but if we access a unknownkey by  m[""] then an key build in it, m["unknownkey"]=0 
    // the value of that corresponding key is 0 
    //cout<<m.at("x")<<endl ; 
    cout<<m["x"]<<endl ;
    cout<<m.size()<<endl;
    /// check presence 
    cout<<m.count("Ghosliya")<<endl ; 
    cout<<m.count("y")<<endl;  

    // erase 
    m.erase("x"); 
    // printing whole map 
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl; 
    }
    
    // using iterator traversing the map 
    unordered_map<string, int> :: iterator it = m .begin() ;
    while(it !=  m.end()){
        cout<<it->first<<" "<<it->second <<endl; 
        it++; 
    }
    // in unordered_map the order of data is random 
    // but in map the  order is same as we inserted 
    
    return 0 ; 
}
*/

// bucket array,(key, value)
// Hash function: using this function we make bucket array 
// Hash function is combination of Hash-code and compresion function 
// hash code: conversion to int (string, char ko)
// the compresion function convert the  output of hash-code to range of array 
/* hashcode: 
1. identity : output =  input 
2. sum of asci values for a string 
3. jaat ; (j*1 + a*2 + a*3 +  t*4) 


collision: same hash-code for two different value 
collision hashing 
-> open hashing: in this head of linked list stored in it, and many  elements in it.
this is also called seperate chaining 
open addressing: 'A' -> 7th index, 'B'-> 7th index (put this is into next empty space)
Hi(a)  = h(a)+Fi(a)  
ith attempt 
-> closed hashing 
linear probing: Fi = i 
quadratic probing: Fi = i^2 
F(0) = 0 
F(1) =  1 
F(2) = 4 

n = total no. of words 
k = word length 
time-complexity of hashcode: O(k) if n>>k T.C = O(1) 
n->  no. of entries in map 
b = no. of boxes availble 
no. of entries in a box = (n/b) (it is called load factor) 
we always encure n/b < 0.7 

if n is increaing then we also have to increase the  number of boxes 
Rehashing: increase  bucket size 
for all entries do hashing again 
   
*/ 


