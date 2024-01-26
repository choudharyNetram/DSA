/*#include<iostream> 
using namespace std ; 
 
int main(){
    int t ; 
    cin>>t ; 
    for(int i = 0 ;i< t ;i++){
        int n  ;
        cin>>n ;
        string s ;
        cin>>s ;
        char curr1 = 'M' ;
        char curr2 = 'm' ;
        int count = 0  ;
        int flag = 1 ; 
        for(int j = 0;  j<n ;j++){
            if(count == 0){
                if(s[j]==curr1   || s[j] ==curr2 ){
                    count = 1; 
                }
                else {
                   
                    flag = 0 ; 
                    break ; 
                }
            }
            else if(count == 1 ){
                if(s[j] == curr1 || s[j] == curr2){
                    count = 1 ;
                }
                else if(s[j] == 'E' || s[j] == 'e'){
                    count = 2 ;
                    curr1 = 'E' ;
                    curr2 = 'e' ;
                }
                else {
                   
                    flag = 0 ; 
                    break ; 
                }
            }
            else if(count ==2 ){
                if(s[j] == curr1 || s[j] == curr2){
                    count = 2 ;
                }
                else if(s[j] == 'O' || s[j] == 'o'){
                    count = 3 ;
                    curr1 = 'O' ;
                    curr2 = 'o' ;
                }
                else {
                    
                    flag = 0 ; 
                    break ; 
                }
            }
            else if (count == 3){
                if(s[j] == curr1 || s[j] == curr2){
                    count = 3 ;
                }
                else if(s[j] == 'W' || s[j] == 'w'){
                    count = 4 ;
                    curr1 = 'W' ;
                    curr2 = 'w' ;
                }
                else {
                    
                    flag = 0 ; 
                    break ; 
                }
            }
            else if(count == 4){
                if(s[j] != curr1 &&  s[j] !=curr2){
                    flag = 0 ; 
                   
                    break ; 
                }
            }
        }
        if(flag && count == 4){
            cout<<"YES"<<endl ; 
        }
        else {
            cout<<"NO"<<endl ; 
        }
    }
}
*/


  /*
// Driver code
int main ()
{
    // Creates a max heap
    priority_queue <int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
  
    // One by one extract items from max heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
  
    return 0;
}
*/

/*
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int size = nums.size() ;
        long long  prefix[size-1] ;
        long long suffix[size-1] ;
        long long multiple = 1 ; 
        for(int i = 0 ;i< size-1 ; i++){
            prefix[i] *= multiple ;
            multiple = prefix[i] ;
        }
        multiple = 1 ; 
        for(int i = size-2 ;i>= 0 ;i--){
            suffix[i] *= multiple ; 
            multiple = suffix[i] ;
        }
        for(int i = 0, i<size-1 ; i++){
            if(gcd(suffix[i], prefix[i]) == 1){
                return i ; 
            }
        }
        return -1 ; 
    }
};

int main(){
    vector<int> nums = {1,2,3,4,4,5,55,66,6,6} ;
    int n = findValidSplit(nums) ;
    cout<<n ; 
    return 0 ; 
}
*/

/*
#include<iostream>
using namespace std ; */
/// 20 10 5 15 13 35 30 40 
/*
int main(){
    int n ; 
    cin>>n  ; 
    int preorder[n] ;
    for(int i = 0 ;i< n ;i++){
        cin>>preorder[i] ; 
    }
    int i = 0 ; 
    int rootData = preorder[i] ;
    /// appliying binary search 
    int j = n-1 ; 
    while(i<=j){
        int mid = (i+j)/2 ;
        if(preorder[mid]>rootData && preorder[mid-1]<rootData){
            i =  mid ;
            cout<<i<<endl;  
            break; 
        } 
        if(preorder[mid] < rootData){
            i =  mid+ 1; 
        }
        else {
            j =  mid-1 ; 
        }
    } 
    return 0 ; 
}

#include<iostream> 
using namespace std ;
int main(){
    int t ;
    cin>>t ;
    for(int j = 0 ;j< t ;j++){
        int n ;
        cin>>n ;
        int arr[n] ;
        for(int i = 0 ;i< n ;i++){
            cin>>arr[i];
        }
        int mini = INT_MIN ;
        int i = 0 ;
        int flag = 1 ; 
        while(i<n-1){
            if(arr[i+1]>=arr[i]){
                arr[i] = mini ;
                arr[i+1] = mini ; 
            }
            else {
                if(i<n-2){
                    arr[i+1] += arr[i]-arr[i+1] ;
                    arr[i+2] += arr[i]-arr[i+1] ;
                }
                else {
                    flag = 0 ; 
                }
            }
            i++; 
        }
        if(flag == 0){
            cout<<"NO"<<endl ; 
        }
        else {
            cout<<"YES"<<endl  ; 
        }
    }
}*/ 
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void updateStartingPoints(vector<int>& startingPoints, vector<int>& endPoints) {
    vector<pair<int, int>> lines;
    for (int i = 0; i < startingPoints.size(); i++) {
        lines.push_back(make_pair(startingPoints[i], endPoints[i]));
    }

    sort(lines.begin(), lines.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < lines.size(); i++) {
        startingPoints[i] = lines[i].first;
        endPoints[i] = lines[i].second;
    }
}

int main() {
    vector<int> startingPoints = {2, 1, 4, 3};
    vector<int> endPoints = {5, 10, 7, 8};

    // Update starting points and end points based on sorted end points
    updateStartingPoints(startingPoints, endPoints);

    // Print the updated starting points and end points
    cout << "Updated Starting Points: ";
    for (int i = 0; i < startingPoints.size(); i++) {
        cout << startingPoints[i] << " ";
    }
    cout << endl;

    cout << "Updated End Points: ";
    for (int i = 0; i < endPoints.size(); i++) {
        cout << endPoints[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

/*#include <iostream>
#include <vector>
#include <algorithm>

bool compareSecondColumn(const std::vector<int>& row1, const std::vector<int>& row2) {
    return row1[1] < row2[1];
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 5, 9},
        {2, 10, 8},
        {3, 7, 7},
        {4, 8, 6}
    };

    std::sort(matrix.begin(), matrix.end(), compareSecondColumn);

    // Print the sorted matrix
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/

#include <iostream>
#include <algorithm>
using namespace std ; 
bool compareSecondColumn(int* row1, int* row2) {
    return row1[1] < row2[1];
}

int main() {
    int matrix[][3] = {
        {1, 5, 9},
        {2, 10, 8},
        {3, 7, 7},
        {4, 8, 6}
    };
    int n = 4 ; 
    int rowCount = n;
    int colCount = 3 ;

    sort(matrix, matrix + rowCount, compareSecondColumn);

    // Print the sorted matrix
    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j < colCount; j++) {
            std::cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
