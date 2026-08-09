#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int len = INT_MIN;
        int start = 0;
        int end = 1;
        int duplicate = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                duplicate++;
            } else if (nums[i] != nums[i + 1] - 1) {
                start = i + 1;
                end = i+1;
                duplicate = 0;
            } else if (nums[i] == nums[i + 1] - 1) {
                
                end = i + 1;
            }
            len = max(len, (end - start - duplicate) + 1);
        }

        if(n==1){
            return 1;
        }
        return len;
    }
};