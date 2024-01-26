#include<iostream>
using  namespace std ;

// Question:- maximum subarray problem 
/*
// brute force approach 
int maxSubArray(vector<int>& nums) {
        int maxi = -1000000 ; 
        for(int i= 0 ;i< nums.size(); i++){
            int sum = 0 ;
            for(int j = i ;j< nums.size() ; j++){
                sum += nums[j];
                if(sum  > maxi){
                maxi = sum  ;
            }
            }
            
        }
        return  maxi ;
}

// maximum subarray algorithm 
/// Kadane's algorithms 
// basic idea of of this algorithm is that if sum  is less than 0 than we update 
//  it by 0 , if greater than 0 than we add next numbers 

int maxSubArray(vector<int>&nums){
        int max_so_far = INT_MIN ;
        int maxEndingHere = 0 ;
        for(int i = 0 ;i< nums.size(); i++){
            maxEndingHere += nums[i];
            max_so_far = max(max_so_far, maxEndingHere);
            if(maxEndingHere < 0){
                maxEndingHere = 0 ;
            }
        }
        return max_so_far ;
}

// question --> is duplicate exists in a array 
// brute  force approach
 bool containsDuplicate(vector<int>& nums) {
        
        for(int i = 0  ; i<nums.size();i++){
            for(int j = i+1 ; j<  nums.size() ;j++){
                if(nums[i]==  nums[j]){
                    return true ; 
                }
            }
        }
        return false ; 
}

// 
bool containsDuplicate(vector<int>& nums) {
        int n = 10000;
        int arr[n];
        for(int i = 0 ;i< n ; i++){
            arr[i ] =  0 ;
        }
        for(int i = 0 ;i< nums.size();i++){
            arr[nums[i]] += 1 ; 
            if(arr[nums[i]] > 1){
                return true ; 
            }
        }
        return false  ; 
    }
    // this upper method is only work for positive number array 

// the next method is that we first sort the array and compare the adjacency elements 

bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i< nums.size()-1 ; i++) {
            if(nums[i] == nums[i+1]){
                return true ; 
            }
        }
        return false ;
}
*/

// one another method is that we can use unordered_map and count all the numbers as many times 
// they appear in the array and if count is greater than 1 for any number than we return true  
// otherwise false 

// map contains two numbers, first is key and second is value 
//  for upper question we store number  and count in the map 
/*
bool containsDuplicate(vector<int>& nums) {
        unordered_map< int, int > m ; 
        for( auto i:nums){
            m[i]++ ;  
        }
        for( auto i: m){
            if(i.second > 1){
                return true ;
            }
        }
        return false ;
}
*/
/// time complexity is O(N) , and space complexity is  O(N) 


/// one more method of upper question is that 

//  using unordered_set 
// if the size of the arrray  and set is same is than no duplicate number  
//  else if size is different than the duplicate number exist  
/*
bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s ;
        for(auto i:nums) s.insert(i);
        if(s.size()==nums.size()) return false ;
        return true ; 
}
*/
// time complexity is O(n), space complexity O(n) ,  



/*Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
*/
// example: Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
//Output: Minimum Difference is 2 
/*
#include<algorithm>

int chocolateDistribution(int *arr, int n ,int  m){
    
    sort(arr, arr+n); // the way of sorting a array by inbuilt function
    
    int minDiff = INT_MAX ;
    for(int i =  0 ; i< n-m ;i++){
        if(arr[m+i-1]-arr[i]<minDiff){
            minDiff = arr[m+i-1]-arr[i];
        }
    }

    return minDiff ;

}

int main(){
    int n = 8 ; 
    int arr[n] = {3, 4, 1, 9, 56, 7, 9, 12}  ;
    int m = 5;
    
    cout<< chocolateDistribution(arr, n , m)<<endl;
    
    return 0 ; 
}
*/

/// Question  number 