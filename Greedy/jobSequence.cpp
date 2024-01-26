///  https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// the important thing in this question is that it is not required to choose a element which deadline is one. 
//  we can do next day task in this also if there were two tasks on the next day and those tasks have more profit 

#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
class Solution 
{
    public:
    // sorted in decending order 
    static bool compare(Job a, Job b){
        return a.profit > b.profit ; 
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, compare) ; 
        int maxDeadline = INT_MIN ; 
        for(int i = 0 ;i<n  ; i++){
            maxDeadline = max(maxDeadline, arr[i].dead) ; 
        }
        
        vector<int> schedule(maxDeadline+1, -1) ; 
        int count = 0 ; 
        int maxProfit = 0 ;
        for(int i = 0 ;i<n ;i++){
            int currProft = arr[i].profit ; 
            int currJobid = arr[i].id ; 
            int currDead = arr[i].dead ;
            for(int k = currDead ;k>0  ;k--){
                if(schedule[k] == -1){
                    count++ ; 
                    maxProfit += currProft ; 
                    schedule[k] = currJobid ; 
                    break ; 
                }
            }
        }
        vector<int>result ; 
        result.push_back(count) ; 
        result.push_back(maxProfit) ; 
        return result ; 
    } 
}; 


/*  in the below solution TLE is coming 
class Solution 
{
    public:
    static bool compareSecondColumn(const vector<int>& row1, const vector<int>& row2) {
        return row1[2] < row2[2];
    }
   
    bool isAllowed(int deadline, vector<int>&howManyTasks){
        if(howManyTasks[deadline]>0){
            return true ; 
        }
        return false ;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<vector<int>> matrix(n, vector<int>(3));
        // sort the array based on deadline 
        for(int i = 0 ;i<n ;i++){
           matrix[i][0] = arr[i].id;
            matrix[i][1] = arr[i].dead;
            matrix[i][2] = arr[i].profit;
        }
        sort(matrix.begin(), matrix.end(), compareSecondColumn);
        int profit = 0 ; 
        int jobDone = 0 ;
        vector<int>howManyTasks(n+1) ; 
        
        for(int i = 0 ; i<=n ;i++){
            howManyTasks[i] = i ; 
        }
        for(int i = n-1 ;i>=0 ;i--){
            int deadline = matrix[i][1] ; 
            if(isAllowed(deadline,howManyTasks)){
                profit += matrix[i][2] ; 
                jobDone++ ; 
                 /// updating the how many  tasks i can do till 
                 int k = howManyTasks[deadline] ; 
                 for(int j = deadline-1 ;j>=1;j--){
                    howManyTasks[j] = min(k-1, howManyTasks[j]) ; 
                }
                 
                 for(int j = deadline ;j<=n ;j++){
                     howManyTasks[j]-- ;
                 }
                 
            }
           
        }
       
        vector<int>ans ; 
        ans.push_back(jobDone) ;
        ans.push_back(profit) ;
        return ans ; 
        
    } 
};  */



