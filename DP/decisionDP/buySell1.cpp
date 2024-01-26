/// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include<map>  
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minIdx = 0 ; 
        int ans = INT_MIN ;
        int n = prices.size() ;  
        for(int i = 0 ;i<n ;i++){
            if(prices[i]<prices[minIdx]){
                minIdx = i ; 
            }
            ans = max(ans, prices[i]-prices[minIdx]) ; 
        }
        if(ans<0){
            return 0 ; 
        }
        return ans ; 
       
    }
};