/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/ 

// For doing this problem, we have to put one queen in each row, each column and no two  queen attack each others 



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Rest of the class implementation...
    void printVisited(vector<vector<int>>& visited, int n ){
        for(int i = 0 ; i<n ;i++){
            for(int j = 0 ;j<n ;j++){
                cout<<visited[i][j]<<" ";
            }
            cout<<endl; 
        }
        cout<<"one time" <<endl;
        cout<<endl;  
    }
    void reverseTraverseDiagonal(vector<vector<int>>& visited, int n, int row, int col) {
        for(int i = 0 ;i<n ;i++){
            if(i != row){
                visited[i][col]-- ; 
            }
        }
        for(int i = 0 ;i<n ;i++){
            if(i != col){
                visited[row][i]-- ; 
            }
            
        }
        int i = row, j = col;
        while (i < n && j < n) {
            if( i != row || j != col){
                visited[i][j]--; 
            }
            i++;
            j++;
        }

        i = row - 1;
        j = col - 1;
        while (i >= 0 && j >= 0) {
            if( i != row || j != col){
                visited[i][j]--; 
            }
            i--;
            j--;
        }
        
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n) {
            if( i != row || j != col){
                visited[i][j]--; 
            }
            i--;
            j++;
        }
        
        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0) {
            if( i != row || j != col){
                visited[i][j]--; 
            }
            i++;
            j--;
        }
        visited[row][col] = 0 ; 
    }

void traverseDiagonal(vector<vector<int>>& visited,int n,  int row, int col) {
    for(int i = 0 ;i<n ;i++){
        if(i != row){
            visited[i][col]++; 
        }
    }
    for(int i = 0 ;i<n ;i++){
        if(i != col){
            visited[row][i]++ ; 
        }
        
    }
    int i = row, j = col;
    while (i < n && j < n) {
        if( i != row || j != col){
                visited[i][j]++; 
            }
        i++;
        j++;
    }

    i = row - 1;
    j = col - 1;
    while (i >= 0 && j >= 0) {
       if( i != row || j != col){
                visited[i][j]++; 
            }
        i--;
        j--;
    }
    
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < n) {
        if( i != row || j != col){
                visited[i][j]++; 
            }
        i--;
        j++;
    }
    
    i = row + 1;
    j = col - 1;
    while (i < n && j >= 0) {
        if( i != row || j != col){
                visited[i][j]++; 
            }
        i++;
        j--;
    }
    visited[row][col] = -1 ; 
}
    void backtrack(int n, int col, vector<vector<string>>&ans, vector<vector<int>>&visited){
         bool flag = 0 ; 
            for(int i = 0 ;i<n ;i++){
                if(visited[i][col] == 0){
                    flag = 1 ; 
                    break ; 
                }
            }
            if(flag == 0){
                return ; 
            }

        if(col==n-1){
             flag = 0 ; 
            for(int i = 0 ;i<n ;i++){
                if(visited[i][col] == 0){
                    visited[i][col] = -1 ; 

                    flag = 1 ; 
                    break ; 
                }
            }
            if(flag == 1){
                vector<string>temp  ; 
                int row ; 
                for(int i = 0 ;i<n ;i++){
                    string s  = ""; 
                    for(int j = 0;j<n ;j++){
                        if(j==col){
                            if(visited[i][j] == -1){
                                row = i ; 
                            }
                        }
                        if(visited[i][j]==-1){
                            s.push_back('Q') ; 
                        }
                        else {
                            s.push_back('.') ; 
                        }
                    }
                    temp.push_back(s) ; 
                }
                ans.push_back(temp)  ; 
                visited[row][col] = 0 ; 
                //reverseTraverseDiagonal(visited, n, row , col) ; 
            }

        }
        else {
            // search in the column col 

            for(int i = 0 ;i<n ;i++){
                if(visited[i][col]==0){
                    visited[i][col] = -1 ; 
                    traverseDiagonal(visited,n, i, col) ; 
                    cout<<"printing the visited"<<i<<" "<<col<<endl; 
                    printVisited(visited, n)  ; 
                    backtrack(n, col+1,  ans , visited)  ; 
                    reverseTraverseDiagonal(visited,n,  i, col) ; 
                    cout<<"print after backtrack "<<i<<" "<<col<<endl; 
                    printVisited(visited, n)  ; 
                    visited[i][col] = 0 ; 
                }
            
            } 
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans ; 
        vector<vector<int>>visited(n, vector<int>(n,0)) ; 
        backtrack(n , 0 , ans, visited) ; 
        return  ans ; 
    }
};

int main() {
    int n = 4; // Number of queens and the size of the chessboard

    Solution solution;
    vector<vector<string>> solutions = solution.solveNQueens(n);

    // Print the solutions
    for (const auto& sol : solutions) {
        for (const auto& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}






/// the below approach by love babbar:   
/*
class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int x=row;
        int y=col;
        
        // check for same row
        while(y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            y--;
        }
        
        x=row;
        y=col;
        
        // check for upper diagonaal
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            x--;
            y--;
        }
        
        x=row;
        y=col;
        
        // check for lower diagonaal
        while(x<n && y>=0)
        {
            if(board[x][y]=='Q')
            {
                return false;
            }
            x++;
            y--;
        }
        
        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        // base case
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        // solve 1 case and rest recursion will handle
        for(int row=0;row<n;row++)
        {
            if(isSafe(row, col, board, n))
            {
                // put queen on board
                board[row][col]='Q';
                solve(col+1, ans, board, n);
                
                // backtrack
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        solve(0, ans, board, n);
        
        return ans;
    }
};*/