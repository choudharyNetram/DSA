///   https://leetcode.com/problems/combination-sum/description/

#include<iostream>
#include<vector>
using namespace std  ; 
#include<algorithm>
class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (target < 0 || index == candidates.size()) {
            return;
        }
        // Skip duplicates
        if (index > 0 && candidates[index] == candidates[index - 1]) {
            backtrack(index + 1, target, candidates, current, ans);
            return;
        }
        // Include the current number
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            // here we backtrack the index "index"
            backtrack(index, target - candidates[index], candidates, current, ans);
            current.pop_back();
        }
        // Exclude the current number
        backtrack(index + 1, target, candidates, current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        backtrack(0, target, candidates, current, ans);
        return ans;
    }
};
