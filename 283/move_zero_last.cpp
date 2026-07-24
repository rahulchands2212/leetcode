#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // int n = nums.size();
        // int first = 0;
        // int second;
        // // set first poniter
        // while (first < n && nums[first] != 0)
        // {
        //     first++;
        // }

        // for (int i = first + 1; i < n; i++)
        // {
        //     if (nums[i] != 0)
        //     {
        //         if (nums[first] == 0 && nums[i] != 0)
        //         {
        //             swap(nums[first], nums[i]);
        //             first++;
        //         }
        //     }
        // }

        //tc=n
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};