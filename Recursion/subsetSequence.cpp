/// printing all the  subset of a array/ vector 
// power set of set ==> set of all subset 
// s = {1,  2, 3}
//   power set  k { {}, {1}, {2}, {3} ,{1,  2},{2, 3} , {3 , 1} , {1,  2, 3} }
/*
class Solution {
    private: 
    void solve (vector<int> nums,vector<int> out , vector<vector<int>> &ans , int idx ){
        // base case 
        if(idx>= nums.size()){
            // here we put out vector in the ans 
            ans.push_back(out);
            return ; 
        }
        // if  we exclude next element 
        //  here only thing we have to done is that we update index 
        solve(nums, out, ans , idx+1);
        // if we include current element 
        // here we include current element(where index is pointing) in the out vector 
        out.push_back(nums[idx]);
        solve(nums, out , ans , idx+1);
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ; 
        vector<int> out ;
        int idx = 0 ; 
        solve( nums ,  out , ans  , idx );
        return ans ; 
        
    }
};

*/



// find all  the subsequence of the array or vector 
/*
void solve(vector<string>& ans, string str, string output, int i) {
    //base case
    if(i>=str.length()) {
        if(output.length()>0)
        ans.push_back(output);
        return ;
        }
    
    //exclude
    solve(ans, str, output, i+1);
    //include
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
    string output = "";
    solve(ans,str,output,0);
    return ans;
	
}
*/



// print all the subset of set of first n natural number 
//see the lecture number 19 of apna college java playlist 
/*
#include<math.h> 
#include<string>
void printsubset(int subset[], int  size){
    if(size == 0){
        cout<<subset
    }
    subset.add(size);
    printsubset(subset,  size-1);
    subset.remove(subset.size()-1);
    printsubset(subset, size-1);

}
    */