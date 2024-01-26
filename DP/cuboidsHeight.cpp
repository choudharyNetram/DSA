/// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/



#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[2] == b[2]) {
        if(a[1] == b[1]){
            return a[0]>b[0] ; 
        }
        return a[1] > b[1]; 
    }
    return a[2] > b[2]; // sorting based on descending order of height 
}

    int maxHeight(vector<vector<int>>& cuboids) {
        // first sort the each block such that maximum number is height, length in middle, and width should be smallest 
        // then sort the whole vector based on descending order of height

        // this question is same as longest dessin subsequence 
        // width, length, height 
        int n = cuboids.size()  ; 
        for(int i = 0 ;i<n ;i++){
            sort(cuboids[i].begin(), cuboids[i].end()) ; 
        }
        sort(cuboids.begin(), cuboids.end(), compare) ; 
        
        vector<int>dp(n) ; 
        for(int i = 0 ;i<n ;i++){
            dp[i] = cuboids[i][2] ; 
        }
        for(int i =  0  ;i<n ;i++){
            for(int j = i+1 ;j<n ;j++){
                if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1]){
                    dp[j] = max(dp[j], dp[i]+cuboids[j][2]) ; 
                }
            }
        }
        //  traverse in the dp vector
        int ans = 0 ; 
        for(int i = 0 ;i<n ; i++){
            ans = max(ans, dp[i]) ; 
        }
        return ans ; 
    }
};

/// one other solution for this question, using same approach
/*
class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        if(b[0] <= a[0] && b[1]<=a[1] && b[2] <= a[2])
            return true;
        else
            return false;
    }
    int solveUsingTabSO(vector<vector<int>>& arr) {
        int n = arr.size();
        //vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || check(arr[curr], arr[prev]))
                    include = arr[curr][2] + nextRow[curr + 1];

                //excude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);   
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {

        //sort every array
        for(auto &a: cuboids) {
            sort(a.begin(), a.end());
        }

        //sort the 2D array
        sort(cuboids.begin(), cuboids.end());

        //apply lis logic
        int ans = solveUsingTabSO(cuboids);
        return ans;
        
    }
};*/


