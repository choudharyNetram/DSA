// implementation of 2-D array in memory is in linear array form 
// index of linear array (c*i)+j , i-row, j-column, c= total number of coulumn
#include<iostream>
using namespace std ; 
int  arr[3][2] = {1, 2, 3, 4, 5,6} ;
// 1 2 
// 3 4 
// 5 6 
int ar[3][2] = {{1,2} , {3,4} , {5,6 }};

/// solve rotate image question , by 90 degree wala 
// link==> https://leetcode.com/problems/rotate-image/

//binary search in 2-D array 
// we can apply binary search in array only when it is sorted starting from first row to last row 
/* Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.*/
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            
            int element = matrix[mid/col][mid%col];
            // we can find row and column with the help of mid 
            // row= mid/totalCol 
            // col = mid%totalCol 
            // this upper value by observation 
            // this observation is based on the 2-d array and linear array of 2-d array 

            if(element == target) {
                return 1;
            }
            
            if(element < target) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
             mid = start + (end-start)/2;    
        }
        return 0;
    }
};
*/
// time complexity = 0(log(mn)) 
// here m,n are number of rows and columns 


// search in a 2-d array 
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 */

// approach --> here we starting from the upper right corner , and will go down or left 
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col-1;
        
        while(rowIndex < row && colIndex>=0 ) {
            int element = matrix[rowIndex][colIndex];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target){
                rowIndex++;
            }
            else
            {
                colIndex--;
            }
        }
        return 0;
    }
};


*/