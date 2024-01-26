// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?leftPanelTab=1




#include <bits/stdc++.h> 
#include<vector>
using namespace std ; 
bool  isSafe(int newx, int newy,int n, vector < vector < int >> & arr, vector<vector<bool>>&visited ){
    if((newx>=0 &&newy>=0 ) && (newx<n && newy <n ) && (arr[newx][newy] == 1 && visited[newx][newy]==0) ){
        return true ; 
    }
    else {
        return false ; 
    }
}
void backtrack(int x, int y,int n,  vector < vector < int >> & arr,vector<string>&ans ,vector<vector<bool>> &visited , string currPath ){
    if(x==n-1 && y==n-1){
        ans.push_back(currPath); 
    }
    // 4 cases, go on left, right,  Up, down 
    // for answer should be in sorting order that's why  order of backtrack is Down,left, Right, Up 
    // isSafe() tell that it is safe go at newx, newY 
    // Down 
    visited[x][y]  = 1 ; 
    if(isSafe(x+1, y,n,  arr, visited)){
        backtrack(x+1, y, n, arr,  ans, visited, currPath + 'D') ;
    }
    // Left 
    if(isSafe(x, y-1, n, arr, visited)){
        backtrack(x, y-1,n,  arr, ans, visited, currPath + 'L') ;
    }
    // Right 
    if(isSafe(x, y+1,n,  arr, visited)){
        backtrack(x, y+1, n, arr, ans, visited, currPath + 'R') ;
    }
    // Up 
    if(isSafe(x-1, y,n,  arr, visited)){
        backtrack(x-1, y, n, arr,  ans, visited, currPath +'U') ;
    }


    visited[x][y] = 0 ; 
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans ; 
    if(arr[0][0]==0){
        return ans; 
    }
    string currPath = "" ; 
    vector<vector<bool>> visited(n, vector<bool>(n,false)) ;
    backtrack(0,  0 , n, arr, ans, visited, currPath) ; 
    return ans  ; 
}



