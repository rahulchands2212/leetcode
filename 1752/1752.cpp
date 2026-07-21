#include<bits/stdc++.h>
using namespace std;

//brute froce;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size()-1;
        //route ker ke sort kiya 
        int i=0;
        while(nums[0]>=nums[n] && i<=n){
            int temp = nums[n];
            for(int i=n;i>0;i--){
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
            i++;
        }
      
        //ab check sort hai ya nhi
        for(int i=0;i<n;i++){
            if(nums[i]<=nums[i+1]){

            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s1;
    vector<int>nums = {1,1,1};
    cout<<s1.check(nums);
    return 0;
}