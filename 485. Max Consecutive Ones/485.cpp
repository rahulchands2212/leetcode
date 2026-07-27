#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0 ,prev = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                current++;
            }
             if(i==(n-1) || nums[i]==0){
                if(current>prev){
                    prev = current;
                }
                current = 0;
            }
        }
        return prev;
        
    }
};

int main(){
    Solution s1;
    vector<int>nums = {1,1,0,1,1,1};
    cout<<s1.findMaxConsecutiveOnes(nums);
    return 0;
}