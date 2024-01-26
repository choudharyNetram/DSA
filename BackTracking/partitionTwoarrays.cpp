///https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1




// User function Template for C++
/*
class Solution{
public: 
     bool spaceOpt(int nums[], int halfSum, int n){
        vector<int>curr(halfSum+1, 0) ; 
        vector<int>next(halfSum+1, 0) ; 
        next[0] = 1 ; curr[0] = 1 ;

        for(int i = n-1 ;i >=0;i--){
            for(int target =  1; target <= halfSum; target++){
                if(target-nums[i]>= 0){
                    curr[target] = next[target] || next[target-nums[i]] ; 
                }
                else {
                    curr[target] = next[target] ; 
                }
                
            }
            next = curr ; 
        }
        
        return curr[halfSum]  ; 
    } 
    
    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for (int i = 0 ; i<N ; i++) {
            totalSum += arr[i];
        }
        
        if (totalSum % 2 != 0) {
            return false;
        }
        int halfSum = totalSum/2 ; 
        return spaceOpt(arr, halfSum, N) ; 
        
    }
};


*/

// the TLE is coming in  below solution. 

class Solution{
public:
    bool solve(int index, int N, int first , int second,int sum,  int arr[]){
        if(index == N){
            if(first == second && first+second == sum){
                return true ; 
            }
            else {
                return false ; 
            }
            
        }
        /// put the index into the first 
        if(solve(index+1, N, first+arr[index], second,sum, arr )){
            return true ; 
        }
        if(solve(index+1, N, first, second+arr[index], sum , arr)){
            return true  ; 
        } 
        return false ; 
        
        
        
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0 ; 
        for(int i = 0 ;i< N ; i++){
            sum += arr[i] ;  
        }
        int first = 0 ;int second = 0 ; 
        return solve(0, N, first, second,sum,  arr) ; 
        
    }
};






