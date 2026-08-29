#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
          if (ans.back()[0] <= intervals[i][1] && ans.back()[1] >= intervals[i][0]) {
                int first = min(ans.back()[0], intervals[i][0]);
                int second = max(ans.back()[1], intervals[i][1]);
                ans.back()[0] = first;
                ans.back()[1] = second;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};