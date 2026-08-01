#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //most voting algo 
        int el = nums[0];
        int count = 0;
     for(int i=0;i<nums.size();i++){
        if(el == nums[i]){
            count++;
        }else{
            count--;
        }

        if(count == 0){
            el = nums[i+1];
        }
      
     }

     //verif
     count = 0;
     for(int i=0;i<nums.size();i++){
        if(el == nums[i]){
            count++;
        }
     }

     if(count>nums.size()/2) return el;
     return -1;
    } 
};