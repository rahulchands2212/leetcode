#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int,int>mpp;
     for(int i=0;i<nums.size();i++){
        int current = nums[i];
        int rem = target-current;
        if(mpp.find(rem)!=mpp.end()){
            return {mpp[rem],i};
        }
        mpp[current] = i;
     }
     return {-1,-1};
        
    }
};