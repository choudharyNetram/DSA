// code-help playlist lecture 10

// finding the unique occurence of numbers 
/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      // /* unordered_map< int, int> numOfOcc ; 
        for(int i  = 0 ;i< arr.size(); i++){
            numOfOcc[arr[i]] = 0  ; 
        }
        for(int i  = 0 ;i< arr.size(); i++){
            numOfOcc[arr[i]] +=  numOfOcc[arr[i]] ; 
        }
        for(int i = 0 ;i< numOfOcc.size() ; i++){
            for(int j = i+1 ; j< numOfOcc.size() ; j++){
                if((numOfOcc[i] == numOfOcc[j] )&& (numOfOcc[i])){
                    return false ; 
                }
            }
        }
        return true ; //*/
       /* set<int> s ;  
        vector<int> v ; 
        unordered_map< int, int> numOfOcc ; 
        for(int i  = 0 ;i< arr.size(); i++){
            numOfOcc[arr[i]] += 1 ; 
        }
        for(auto i:numOfOcc){
            v.push_back(i.second) ; 
        }
        for(auto i:numOfOcc){
            s.insert(i.second) ; 
        }
        if(s.size() == v.size() ){
            return true ; 
        }
        else {
            return false ; 
        }

        

        return false ; 
    }
};
*/

/// 
/*

#include<iostream> 
using namespace std;
/// pivot  is basically a number from a change can came in a sorted array {8, 10 ,13 , 1 ,3 4}
// in the above array 13 and 1 is pivot 
// {1, 2, 3, 4 ,8 } --> here pivot is the 8 or 1 
// the  use of pivot in the rotated sorted array 
int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

//

int main() {
    int arr[5] = {1, 3, 8, 10, 17};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}



// searching in a rotated sorted array 
///     https://leetcode.com/problems/search-in-rotated-sorted-array/description/

/// here we first find  the pivot element than if the key or (number of searched ) is only avialble of the
//  right of the pivot or right of the pivot   
/// 2 4 5 6 8 9 1 4 ==> like in this array the pivot is 1 or 9 so we compare key with pivot and decide where I can found the key

#include <bits/stdc++.h> 
int binarySearch(vector<int>& arr, int  s, int en , int size, int key) {

    int start = s;
    int end = en ;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}
int getPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int findPosition(vector<int>& arr, int n, int k)
{
    int  pivot =  getPivot(arr ,n );
    if(k>= arr[pivot] && k<= arr[n-1] ){
        return binarySearch( arr, pivot,  n-1 , n ,  k);
    }
    else {
        return binarySearch(arr, 0 , pivot , n, k );
    }
}
*/
//// finding  squareroot with the help of binary search 
#include<iostream>
using namespace std ;

int mySqrt(double x) {
int st = 0  ; 
int end = x ;
long long int ans = -1 ; 
long long int mid = st+ (end-st)/2 ;
while(st<=end){
    long long square = mid*mid ; 
    if( square == x){
        ans = mid ; 
        break ; 
    }
    else  if ( square>  x){
        end = mid-1  ; 
    }
    else {
        ans = mid ; // this is for those integers those don't have perfect square root 
        st = mid+1 ; 
    }
    mid = st+ (end-st)/2  ; 
}
return ans ; 


}
/// double can do both of work integer and float 
double  morePrecision(double n , double  tempsol,int precision){
    double factor = 1 ;
    double ans  =  tempsol ; 
    for(int i = 0 ; i< precision ;i++){
        factor = factor/10 ;
        for(double j = ans ; j<=tempsol+((factor)*1000) ; j = j+factor){
            //cout<<factor<<endl; 
            if(j*j < n){
                //cout<<j<<endl ;
                //cout<<"jaat da muqabala khi bhi  ";
                
                ans = j ; 
                //cout<<ans<<endl  ; 
            }
        }
    }
    return ans ; 
}
int  main(){
    double n ;
    cin>>n ; 
    int  tempsol = mySqrt(n) ;
    //cout<< tempsol <<endl  ; 
    // here temp  soultion is the only integer part of square root 
    //  for finding value till any number decimal point 
    // here we first check (tempsol+0.1)**2 < n, save it in answer, (tempsol+0.2)**2 <n save it in answer;
    // if any condition is failed than we find  the next number after point 
    cout<< morePrecision(n,  tempsol, 3)<<endl ;
    return 0  ; 
}



/// lecture 15 

/// how we can know that we can apply binary search  in a question?
/// answer:- if by any method we can reduce the search space in array than we can apply binary search in this question

/*
/// this is the book allocation problem 
// lecture-15 
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
                return false;
            }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum; /// we know that our answer is must in 0th and sum of the array 
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}


*/

/// agresive cow problem
// lecture 15 
/*
bool isPossibleSol(vector<int> &stalls, int k , int mid){
    /// stalls[i]-stalls[j]>=mid 
    int cowCount = 1 ; 
    int lastCow = stalls[0] ;
    
    for(int i = 0 ;i<stalls.size() ; i++){
        if(stalls[i]-lastCow>= mid){
            cowCount++ ;
            if(cowCount == k){
                return true; 
            }
            lastCow = stalls[i] ;/// here we update lastcow because we need to because we only care about minium distance of cows  
        }
    }
    return false ; 
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
   int s = 0 ; 
   int maxi = -1 ; 
   for(int i = 0 ; i<stalls.size(); i++){
       maxi = max(maxi, stalls[i]);
   }
    int en = maxi ; // here we give maxi value of index where cow is sitting 
    int ans = -1 ; 
    int mid = s + ((en-s)/2) ; 
    while(s<=en){
        if(isPossibleSol(stalls, k  , mid )){
            s = mid+1 ; 
            ans = mid ;
        }
        else {
            en = mid-1 ; 
        }
        mid  = s + ((en-s)/2) ; 
    }
    return ans ; 
}
*/


//home work of binary search which you didn't done yet 
// link in lecture 15 in description 
/*   https://www.spoj.com/problems/EKO/   
https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174
*/


/// lecture 21 
/// rotate array by k indexes 
// Given an array, rotate the array to the right by k steps, where k is non-negative.


class Solution {
public:
  /*  void rotate(vector<int>& nums, int k) {
        vector<int>temp(nums.size());
        for(int i = 0 ; i< nums.size(); i++){
            if(i+k<nums.size()){
                temp[i+k] = nums[i] ;
            }
            else {
                temp[(i+k)%nums.size()]= nums[i] ; 
            }
        }
        for(int i = 0 ;i<nums.size() ; i++){
            nums[i] = temp[i] ; 
        } 
    }*/
     void rotate(vector<int>& nums, int k) {
        vector<int>temp(nums.size());
        for(int i = 0 ; i< nums.size(); i++){
            temp[(i+k)%nums.size()]= nums[i] ; 

        }
         nums = temp ; 
     }
    
};
#include<vector>
class Solution {
public:
  /// best solution: Reverse the string partly, then reverse the hole string.
    void rotate(vector<int>&nums, int numsSize, int k) {
        int temp;
        k = k%numsSize;
        for (int i = 0, j = numsSize-k-1 ; i < j ;i++,j--)
        {
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
        for (int i = numsSize-k, j = numsSize-1 ; i < j ;i++,j--)
        {
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
        for (int i = 0, j = numsSize-1 ; i < j ;i++,j--)
        {
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
     void rotate(vector<int>& nums, int k) {

         /* the below solution uses O(n) space
        vector<int>temp(nums.size());
        for(int i = 0 ; i< nums.size(); i++){
            temp[(i+k)%nums.size()]= nums[i] ; 

        }
         nums = temp ; */
     }
    
};

/// checking a array is sorted and rotated or not 
//Given an array nums, return true if the array was originally sorted in
// non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0  ; 
        for(int i = 0 ; i< nums.size()-1; i++){
            
                if(nums[i+1]<nums[i]){
                    count++ ; 
                }
            
            
        }
        if(nums.size()>= 2){
        
                if(nums[0]<nums[nums.size()-1]){
                    count++ ; 
                }
            }
            
        
            if(count < 2){
                return true ; 
            }
            else {
                return false ; 
            }


    }
};

// sum of two arrays 
/* Sample Input 1:
2
4 1 
1 2 3 4
6
3 2
1 2 3
9 9    
Sample Output 1:
1 2 4 0
2 2 2*/

// we can also do this question without using any extra space
#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int x = max(m,n ) ;
     vector<int>arr(x);
    int  i = n-1 ;
    int j = m-1 ;
    int carry = 0 ;
    x = x-1 ; 
    
    while(i>= 0 || j>=0){
        if(i<=-1){
             arr[x] = (b[j]+carry)%10 ; 
            carry = (b[j]+carry)/10 ; 
        }
        else if(j<=-1){
             arr[x] = (a[i] +carry)%10 ; 
            carry = (a[i]+carry)/10 ; 
        }
        else {
        arr[x] = (a[i]+b[j]+carry)%10 ;
        carry = (a[i]+b[j]+carry)/10 ;
        }
        i-- ; j-- ; x-- ; 
    }
    x = max(m,n ) ;
    if(carry){
        vector<int>arr1(x+1);
        arr1[0] = 1 ; 
        for(int i = 1 ; i<= x ;i++){
            arr1[i] = arr[i-1];
           
        }
         return arr1 ; 
    }
    return arr ; 
}

/// second method of uper question  is that,  we can use push_back or push_front instead of treating vector like a array 
// we initilize arr --> vector<int>arr ; 