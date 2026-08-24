#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                 if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long int sum =
                        (long long int)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> subans = {nums[i], nums[j], nums[k],
                                              nums[l]};
                        st.insert(subans);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }

                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    } else if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    }
                }
            }
        }
        vector<vector<int>> ans = {st.begin(), st.end()};
        return ans;
    }
};