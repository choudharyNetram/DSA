//// https://leetcode.com/problems/edit-distance/



#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int solve(string &word1, string &word2, int i , int j, vector<vector<int>>&dp){
        if(i==word1.size()){
            return word2.size()-j  ;
        }
        if(j==word2.size()){
            return word1.size() - i ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }   
        if(word1[i]==word2[j]){
            return dp[i][j] = solve(word1, word2, i+1, j+1, dp) ; 
        }
        else {
            int insertAns = 1+solve(word1, word2, i, j+1, dp) ; 
            int deleteAns = 1+solve(word1, word2, i+1 , j, dp) ;
            int replaceAns = 1+solve(word1, word2, i+1, j+1, dp) ; 
            return dp[i][j] = min(insertAns, min(deleteAns, replaceAns)) ;
        }


    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1)) ; 
        return solve(word1, word2, 0, 0, dp) ; 

        /*
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> matrix(m+1, vector<int>(n+1));
       
        for(int i = 0 ;i<=m ;i++){
            for(int j = 0 ;j<=n ;j++){
                
                if(i == 0 ){
                    matrix[i][j] = j; 
                }
                else if(j==0){
                    matrix[i][j] = i ; 
                }
                else{
                    if(word1[i-1]==word2[j-1]){
                        matrix[i][j] = matrix[i-1][j-1]; 
                    }
                    else {
                        matrix[i][j] = min(matrix[i-1][j]+1, min(matrix[i][j-1]+1, matrix[i-1][j-1]+1));
                    }
                    
                   
                }
            }
        }
        return matrix[m][n] ;*/
    }
};