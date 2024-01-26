#include<iostream>
using namespace std ;
#include<stack>
// reversing string s using a stack 
/*
int main(){
    string str = "reverse";
    stack<char> st ; 
    for(int i = 0 ;i< str.length() ;i++){
        char ch = str[i];
        st.push(ch);
    }
    str = "" ; 
    while(!st.empty()){
        str = str+st.top();
        st.pop();
    }
    for(int i = 0 ;i< str.length() ;i++){
        cout<<str[i] ; 
    }
    return 0 ;
}
*/
///// deleting the middle element of the stack 
/*
#include <bits/stdc++.h> 

void middleDeleter(stack<int>&inputStack, int count , int size){
    if(count == size/2){
        inputStack.pop();
        return ; 
    }
    int num = inputStack.top();
    inputStack.pop();
    middleDeleter(inputStack, count+1 , size) ; 
    inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0 ; 
    middleDeleter(inputStack, count , N) ;
    
   
}
*/

///// valid parenthesis 
/*
class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        for(int i = 0 ; i< s.length() ;  i++){
            if(s[i]== '{' || s[i]== '(' || s[i]== '[' ){
                st.push(s[i]);
            }
            else {
                if(!st.empty()){
                    if(isMatches(st.top(),  s[i])){
                        st.pop();
                    }
                    else{
                        return false ;
                    }
                }
                else{
                    return false ;
                }
            }
        
        }
       if(st.empty()) {
           return true ;
       }
        else {
            return false ;
        }
    }
    bool isMatches( char a , char b ){
        if((a == '(' && b == ')' ) || (a == '[' && b == ']') || (a == '{' && b == '}')) {
            return true ; 
        }
        
        else {
            return false ; 
        }
    }
};
*/


// insert an element at its bottom in a given stack 
/*
#include <bits/stdc++.h> 

void PushBottom(stack<int>& myStack, int x){
    if(myStack.empty()){
     myStack.push(x) ;
      return ; 
    }
    int num = myStack.top();
      myStack.pop();
     PushBottom(myStack, x);
       myStack.push(num);
   
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
     PushBottom(myStack, x);
      return myStack ;
}
*/
/*
// reverse a stack  
void PushBottom(stack<int>& myStack, int x){
    if(myStack.empty()){
     myStack.push(x) ;
      return ; 
    }
    int num = myStack.top();
      myStack.pop();
     PushBottom(myStack, x);
       myStack.push(num);
   
}

void reverseStack(stack<int> &stack) {
    
   if(stack.empty()){
      return ; 
    }
    int num = stack.top();
     stack.pop();
     
    reverseStack(stack);
    PushBottom(stack, num);
    
}*/



/* sorting a stack in deceding order 
#include <bits/stdc++.h> 
void Sort( stack<int> &stack, int num){
    if(stack.empty()){
        stack.push(num);
        return ; 
    }
    int x= stack.top();
    if(num>x){
        stack.push(num);
    }
    else{
        stack.pop();
        Sort(stack, num);
        stack.push(x);
    }
    
    
}
void sortStack(stack<int> &stack)
{
    if(stack.empty()){
        return; 
    }
    int num= stack.top();
    stack.pop();
    sortStack(stack);
    Sort(stack, num);
    
}
*/


// return true if Redundant Brackets(faltu ke brackets ) is exist in string 

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> stack ;
    for(int i= 0 ; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='+'|| s[i]=='-'|| s[i]=='*'|| s[i]=='/'){
            stack.push(s[i]);
        }
        else if(s[i]==')'){
            if(stack.top()=='('){
                return true ; 
            }
            else {
                  while(stack.top()!='('){
                      stack.pop();
                  }
            }
            stack.pop() ;
          
        }
    }
    return false ; 
}



// making brackets string valid if it is possible 

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
      stack<char> stack; 
     if(str.size()%2==1){
         return -1 ; 
     }
     for(int i = 0 ;i<str.size(); i++){
         if(str[i]=='{'){
             stack.push(str[i]);
         }
         else {
             if(!stack.empty() && stack.top()=='{'){
                 stack.pop();
             }
             else {
                 stack.push(str[i]);
                
             }
             
         }
     }
    int x = 0 ; 
    int y = 0 ; 
    while(!stack.empty()){
        if(stack.top()=='{'){
            x++; 
        }
        else {
            y++ ; 
        }
        stack.pop() ;
    }
    // three main types of invalid string after removing valid from it 
    /// 1. }}}}    2.{{{{{    3. }}}}{{{{ in part three two types it can be 1.x and y both even or (x and y both odd)
    // x+y can't be negative, we handle this case at upper 
    // by following we find a short formula of ans 
    int ans = ((x+1)/2) + ((y+1)/2) ; 
   return ans  ; 
    
}



// area of histogram 
//   https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};


// celebrity problem:- In a party celebrity is a person who don't know other persons and all other person knows him than he is a celebrity 
//A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
//optimized approach of this problem :- first put all the persons in the stack than pop two upper elements than check that A knows B or B knows A.
// if A knows B than push B else push A into stack. Do this process until one element remains in stack. 
// Lecture-57 
class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and copare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
        
    }
};




/// Lecture-57 Question-2 
//Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.
/*   the matrix looks like this  
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
*/
// algorithms 


// code 
#include<bits/stdc++.h> 
#define MAX 1000

class Solution{
    private: vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> arr(m) ;
        for(int i = 0;i< m ;i++){
            arr[i] = 0 ; 
        }
        int max_area = 0 ; 
        int area ; 
        for(int i = 0 ;i< n ; i++){
            for(int j = 0;j< m ; j++){
                if(M[i][j]==0){
                    arr[j] = 0 ; 
                }
                else {
                    arr[j]++ ; 
                }
            }
            area = largestRectangleArea( arr);
            max_area = max(max_area , area );
            
            
        }
      return max_area ;   
    }
};

