// https://leetcode.com/problems/combination-sum-ii/description/

#include<iostream>
#include<vector>
using namespace std  ; 
#include<algorithm>
 class Solution {
public:
    void recurs(int index, int n, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& validans) {
        if (target == 0) {
            ans.push_back(validans);
            return;
        }
        for (int i = index; i < n; i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            validans.push_back(candidates[i]);
            recurs(i + 1, n, candidates, target - candidates[i], ans, validans);
            validans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> validans;
        sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        recurs(0, n, candidates, target, ans, validans);
        return ans;
    }
};

/* the below solution is correct but not efficient 

    void findSubsets(int ind, vector < int > & nums, vector < int > & currsubset, vector < vector < int >> & ans,  int target) {
        int sum = 0; 
        for(int i = 0;i<currsubset.size();i++){
            sum += currsubset[i]  ;
        }
        if(target==sum){
            ans.push_back(currsubset);
        }
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
                currsubset.push_back(nums[i]);
                findSubsets(i + 1, nums, currsubset, ans,target);
                currsubset.pop_back();
         }
      }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector < vector < int >> ans;
         vector < int > currsubset;
         sort(candidates.begin(), candidates.end());
         findSubsets(0, candidates, currsubset, ans, target);
         return ans;
    }*/