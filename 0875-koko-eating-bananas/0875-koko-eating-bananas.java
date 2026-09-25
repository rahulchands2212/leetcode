class Solution {
    public long hourCalculat(int[] piles, int k) {
        long hours = 0;
        for (int i = 0; i < piles.length; i++) {
            hours = hours + (piles[i] / k);
            if (piles[i] % k != 0) {
                hours++;
            }
        }
        return hours;
    }

    public int minEatingSpeed(int[] piles, int h) {
        //max find
        int maxi = piles[0];
        for (int i = 0; i < piles.length; i++) {
            maxi = Math.max(maxi, piles[i]);
        }

        //pick k bs
        int low = 1;
        int high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long hours = hourCalculat(piles, mid);
            if (hours<=h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;

    }
}