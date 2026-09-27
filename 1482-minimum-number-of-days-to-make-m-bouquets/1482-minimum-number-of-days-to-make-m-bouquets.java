class Solution {
    public int check(int[] nums, int mid, int k) {
        int n = nums.length;
        int count = 0;
        int bouquests = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                count++;
            } else {
                count = 0;
            }
            if (count == k) {
                count = 0;
                bouquests++;
            }
        }
        return bouquests;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        //edge case
        int totalflower = m * k;
        int n = bloomDay.length;
        if (totalflower > n) {
            return -1;
        }

        //max and mini
        int high = bloomDay[0];
        int low = bloomDay[0];
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] > high) {
                high = bloomDay[i];
            }
            if (bloomDay[i] < low) {
                low = bloomDay[i];
            }
        }

        //binary search
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int day = check(bloomDay, mid, k);
            if (day >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;

    }
}