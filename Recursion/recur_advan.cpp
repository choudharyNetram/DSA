
// phone  keypad problem 
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
//that the number could represent. Return the answer in any order.
//A mapping of digits to letters (just like on the telephone buttons) is given below.
// Note that 1 does not map to any letters.

// string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};

/* 
class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};
*/


// // rate in a maze problem   
/* question=> 
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.  */
/*
class Solution{
    public:
    
    bool isPossible(vector< vector <int>> &m, vector< vector<int>> visited, int x, int y , int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector< vector <int>> &m, vector< vector<int>> visited,string path,int n, int x, int y, vector <string> &ans){
        //Base case
        if( x == n-1 && y == n-1){
            ans.push_back(path);
            return ;
        }
        
        visited[x][y] = 1;
        //Down
        int newx = x+1;
        int newy = y;
        if(isPossible(m, visited, newx, newy ,n)){
            path.push_back('D');
            solve(m, visited, path, n, newx,newy,ans);
            path.pop_back();
        }
        
        //Up
        newx=x-1;
        newy=y;
        if(isPossible(m, visited, newx, newy,n)){
            path.push_back('U');
            solve(m, visited, path, n, newx,newy,ans);
            path.pop_back();
        }
        
        //Left
        newx=x;
        newy=y-1;
        if(isPossible(m, visited, newx, newy,n)){
            path.push_back('L');
            solve(m, visited, path, n, newx,newy,ans);
            path.pop_back();
        }
        
        //Right
        newx=x;
        newy=y+1;
        if(isPossible(m, visited, newx, newy,n)){
            path.push_back('R');
            solve(m, visited, path, n, newx,newy,ans);
            path.pop_back();
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector <vector<int>> visited=m;
        string path="";
        int srcx=0;
        int srcy=0;
        vector <string>  ans;
        if(m[0][0]==0){
            return ans;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j]=0;
            }
        }
        solve(m, visited, path,n , srcx, srcy, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    
*/
