#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;

        //two pointer
        int i = 0;
        int count = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]){
                count++;
            }else{
                if(count>n/3){
                    ans.push_back(nums[i]);
                }
                i = j;
                j--;
                count = 0;
            }
        }

        if(count>n/3){
             ans.push_back(nums[i]);
        }
        
        return ans;
    }
};