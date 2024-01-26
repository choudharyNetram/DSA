
////    https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 

struct Item{
    int value;
    int weight;
};
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
     static bool compare(pair<double, Item> a, pair<double, Item>b) {
        return a.first > b.first ;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> v ; 
        for(int i = 0; i<n ;i++){
            double perUnitValue = (1.0*arr[i].value)/arr[i].weight ; 
            pair<double, Item> p = make_pair(perUnitValue,  arr[i]) ; 
            v.push_back(p) ; 
        }
        sort(v.begin(), v.end(), compare) ; 
        double totalValue = 0  ; 
        for(int i = 0 ;i<n ;i++){
            if(v[i].second.weight > W){
                /// we can only take fraction of this item 
                totalValue += W * v[i].first ; 
                W = 0 ; 
                break ; 
                
            }
            else {
                totalValue += v[i].second.value ; 
                W -= v[i].second.weight ; 
            }
        }
        return totalValue ; 
    }
        
};  


/*
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
     static bool compare(const vector<int>& row1, const vector<int>& row2) {
        return row1[0] < row2[0];
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // first make another array valeus[i]/weight[[i]] 
        // sort all three array based on new array 
        //  starting se utata ja jb tk currweight<totalweight 
        vector<vector<int>>v(n,vector<int>(3)) ; 
        for(int i = 0;i<n ;i++){
            v[i][0] = static_cast<double>(arr[i].value) / arr[i].weight;
            v[i][1] = arr[i].value ; 
            v[i][2] = arr[i].weight; 
        }
        sort(v.begin(), v.end(), compare);
        double ans = 0 ; 
        for(int i = n-1 ;i>=0 ; i--){
            if(W<=0){
                break; 
            }
            if(W>=v[i][2]){
                ans += v[i][1] ; 
                W -= v[i][2] ; 
            }
            // value/weight 
            else {
               // ans += (double(v[i][1]/v[i][2]))*W ; 
               ans += (static_cast<double>(v[i][1]) / v[i][2]) * W;

                W = 0 ;
            }
           
        }
        return ans ; 
    }
        
};  */ 






