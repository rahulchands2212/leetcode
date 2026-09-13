class Solution {
    public int findNumbers(int[] nums) {
        int n = nums.length;
        int evencounter = 0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            int count = 0;
            while(num!=0){
                count++;
                num = num/10;
            }
            if(count%2==0){
                evencounter++;
            }
        }
        return evencounter;
    }
}