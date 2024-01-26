// https://leetcode.com/problems/sudoku-solver/ 

#include<iostream> 
#include<vector> 
using namespace std ; 

class Solution {
public:
// time-complexity of this: 9^n 

bool isSafe(int row, int col,vector<vector<char>>& board ,int n,   int val){
    for(int i = 0 ;i<n ;i++){
        // checking row
        if(board[row][i] ==  val){
            return false ; 
        }
        // col check 
        if(board[i][col] == val){
            return false ; 
        }
        //  3X3 matrix check 
        if(board[3*(row/3) + i/3][3*(col/3) + i%3 ] == val){
            return false ; 
        }
    }
    return true ; 
}

bool solve(vector<vector<char>>& board){
    int n = board[0].size() ; 
    for(int row = 0; row<n ;row++){
        for(int col = 0 ;col<n ;col++){
            // is cell empty 
            if(board[row][col]=='.'){
                for(char val = '1' ; val<='9' ; val++){
                    if(isSafe(row, col, board, n,  val)){
                        board[row][col] = val ; 
                        //  aage solution possible or not
                        bool solutionExist = solve(board) ; 
                        if(solutionExist){
                            return true ; 
                        }
                        else {
                            // backtrack 
                            board[row][col] = '.'  ; 
                        }
                    }
                }
                return false ; 
            }
        }
    }
    return true ; 
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board) ; 
    }
};