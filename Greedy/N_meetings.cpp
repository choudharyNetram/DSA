/// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>

class Solution
{
    public:
    
    // the below function is sorting the array based on the ending pointing of interval 
    void updateStartingPoints(int* startingPoints, int* endPoints, int size) {
        pair<int, int>* lines = new std::pair<int, int>[size];
        for (int i = 0; i < size; i++) {
            lines[i] = make_pair(startingPoints[i], endPoints[i]);
        }
    
        sort(lines, lines + size, [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
    
        for (int i = 0; i < size; i++) {
            startingPoints[i] = lines[i].first;
            endPoints[i] = lines[i].second;
        }
    
        delete[] lines;
}

    int maxMeetings(int start[], int end[], int n)
    {
        updateStartingPoints(start, end, n);
        int count = 0;
        int maxVisi = -100 ; 
        for(int i = 0 ;i<n; i++){
            if(start[i]>maxVisi){
                count++; 
               // cout<<m[end[i]]<<" "<<end[i]<<endl; 
                maxVisi = max(maxVisi,end[i])  ;
            }
            
        }
        return count; 
    }
};

