


#include <iostream>
#include <vector>

using namespace std;
/**/
class Solution {
public:
    int recur(vector<int>& nums1, vector<int>& nums2,  int n , int i,int last,  int curr, int prevMax){
        if(i==n){
            return max(curr,prevMax); 
        }
        if(i==0){
            int first = recur(nums1, nums2, n, i+1, nums1[i], 1, 1) ; 
            int second = recur(nums1, nums2, n, i+1, nums2[i], 1, 1) ; 
            first =  max(first,second) ; 
            cout<<first<<" " <<i<<endl;
            return first ; 
        }
        // pick from the first array 
        int ans1 = 0; 
        int ans2 =0 ; 
        if(nums1[i]>=last){
            ans1 = max(prevMax,recur(nums1, nums2, n, i+1, nums1[i], curr+1, max(prevMax,curr+1))) ; 
        }
        else{
            ans1 = max(prevMax, recur(nums1, nums2, n, i+1, nums1[i], 1, max(prevMax, curr))) ; 
        }
        if(nums2[i]>=last){
            ans2 = max(prevMax,recur(nums1, nums2, n, i+1, nums2[i], curr+1, max(prevMax,curr+1))) ; 
        }
        else{
            ans2 = max(prevMax, recur(nums1, nums2, n, i+1, nums2[i], 1, max(prevMax, curr))) ; 
        }
        ans1 =  max(ans1, ans2) ; 
        cout<<ans1<<" " <<i<<endl; 
        return ans1 ; 
    }
    
   /* 
int Memo(vector<int>& nums1, vector<int>& nums2,  int n , int i,int last,  int curr, int prevMax, vector<vector<int>>&dp, int wh){
        if(i==n){
            return dp[i][wh] = max(curr,prevMax); 
        }
        if(dp[i][wh] != -1){
            return dp[i][wh] ;
        }
        if(i==0){
            int first = Memo(nums1, nums2, n, i+1, nums1[i], 1, 1,dp, 0) ; 
            int second = Memo(nums1, nums2, n, i+1, nums2[i], 1, 1, dp, 2) ; 
            dp[i][wh] = max(first,second) ;
            cout<<dp[i][wh]<<" " <<i<<endl;  
            return dp[i][wh] ; 
        }
        
        // pick from the first array 
        int ans1 = 0; 
        int ans2 =0 ; 
        if(nums1[i]>=last){
            ans1 = max(prevMax,Memo(nums1, nums2, n, i+1, nums1[i], curr+1, max(prevMax,curr+1),dp, 0)) ; 
        }
        else{
            ans1 = max(prevMax, Memo(nums1, nums2, n, i+1, nums1[i], 1, max(prevMax, curr),dp, 1)) ; 
        }
        if(nums2[i]>=last){
            ans2 = max(prevMax,Memo(nums1, nums2, n, i+1, nums2[i], curr+1, max(prevMax,curr+1),dp, 2)) ; 
        }
        else{
            ans2 = max(prevMax, Memo(nums1, nums2, n, i+1, nums2[i], 1, max(prevMax, curr),dp, 3)) ; 
        }
        
         dp[i][wh]= max(ans1, ans2) ; 
        cout<<dp[i][wh]<<" " <<i<<endl; 
        return dp[i][wh] ; 
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ; 
        vector<vector<int>>dp(n+1, vector<int>(4, -1))  ;
        return recur(nums1, nums2, n, 0, -1, 0, 0)  ; 
        return Memo(nums1, nums2, n, 0, -1, 0, 0,dp, 1) ; 
    }

*/
int Memo(vector<int>& nums1, vector<int>& nums2, int n, int i, int last, int curr, int prevMax, vector<vector<int>>& dp) {
    if (i == n) {
        return max(curr, prevMax);
    }
    if (dp[i][last] != -1) {
        return dp[i][last];
    }
    if (i == 0) {
        int first = Memo(nums1, nums2, n, i + 1, nums1[i], 1, 1, dp);
        int second = Memo(nums1, nums2, n, i + 1, nums2[i], 1, 1, dp);
        first = max(first, second);
        cout << first << " " << i << endl;
        return dp[i][last] = first;
    }

    int ans1 = 0;
    int ans2 = 0;

    if (nums1[i] >= last) {
        ans1 = max(prevMax, Memo(nums1, nums2, n, i + 1, nums1[i], curr + 1, max(prevMax, curr + 1), dp));
    } else {
        ans1 = max(prevMax, Memo(nums1, nums2, n, i + 1, nums1[i], 1, max(prevMax, curr), dp));
    }

    if (nums2[i] >= last) {
        ans2 = max(prevMax, Memo(nums1, nums2, n, i + 1, nums2[i], curr + 1, max(prevMax, curr + 1), dp));
    } else {
        ans2 = max(prevMax, Memo(nums1, nums2, n, i + 1, nums2[i], 1, max(prevMax, curr), dp));
    }

    ans1 = max(ans1, ans2);
    cout << ans1 << " " << i << endl;
    return dp[i][last] = ans1;
}

int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(101, -1));
    return Memo(nums1, nums2, n, 0, -1, 0, 0, dp);
}
};
int main() {
    Solution solution;

    // Example test case
    vector<int> nums1 = {2,1,2,7};
    vector<int> nums2 = {9,2,6,1};
    int result = solution.maxNonDecreasingLength(nums1, nums2);

    cout << "Maximum non-decreasing length: " << result << endl;

    return 0;
}

/*
2
4
4
4
4
4
4
2
4
4
4
4
4
4
*/