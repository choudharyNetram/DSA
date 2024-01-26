#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& permutation, vector<bool>& used) {
    if (permutation.size() == nums.size()) {
        permutations.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i])
            continue;

        used[i] = true;
        permutation.push_back(nums[i]);
        backtrack(nums, permutations, permutation, used);
        permutation.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    vector<int> permutation;
    vector<bool> used(nums.size(), false);
    backtrack(nums, permutations, permutation, used);
    return permutations;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    cout << "Permutations:" << endl;
    for (const vector<int>& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}






/// permutation of a string  
// str = "abc"
// "abc" , "acb" , "bac" , "bca" , "cab", "cba" 
/*
class Solution {
public:

    void solve(vector<int>nums , int index , vector<vector<int>> &ans){
        if(index >= nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=index ; i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,index,ans);
        return ans;
    }
};*/



// print all the combination of string

void printcomb(string s, string  permutation){
    if(s.length()==0){
        cout<<permutation<<endl ;
        return ; 
    }
    for(int i = 0 ; i< s.length();  i++){
        char currchar = s[i];
        string new_str = s.substr(0, i)+ s.substr(i+1);
        printcomb(new_str , permutation+currchar);
    }
}
int main(){
    string s = "abcd";
    string permutation = "";
    printcomb(s, permutation);
    return 0 ;
}

