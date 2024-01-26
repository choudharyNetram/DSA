/// https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1


#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 

class Solution {
public:
    vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < N; i++) {
            meetings.push_back({S[i], F[i]});
        }

        vector<int> originalIndices(N);
        for (int i = 0; i < N; i++) {
            originalIndices[i] = i + 1;
        }

        sort(originalIndices.begin(), originalIndices.end(), [&](const int& a, const int& b) {
            return F[a - 1] < F[b - 1];
        });

        vector<int> ans;
        int maxVisi = -100;
        for (int i = 0; i < N; i++) {
            if (S[originalIndices[i] - 1] > maxVisi) {
                ans.push_back(originalIndices[i]);
                maxVisi = max(maxVisi, F[originalIndices[i] - 1]);
            }
        }
        sort(ans.begin(), ans.end()) ; 
        return ans;
    }
};

/* the below solution is wrong, for some requirements, where the output time is same, which one to take
when starting, ending time is same then which one index is  to take.  

class Solution {
public:
    vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < N; i++) {
            meetings.push_back({S[i], F[i]});
        }

        map<pair<int, int>, int> indexMap;
        for (int i = 0; i < N; i++) {
            indexMap[meetings[i]] = i + 1;
        }

        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        vector<int> ans;
        int maxVisi = -100;
        for (int i = 0; i < N; i++) {
            if (meetings[i].first > maxVisi) {
                ans.push_back(indexMap[meetings[i]]);
                maxVisi = max(maxVisi, meetings[i].second);
            }
        }
        sort(ans.begin(), ans.end()) ; 
        return ans;
    }
};

*/