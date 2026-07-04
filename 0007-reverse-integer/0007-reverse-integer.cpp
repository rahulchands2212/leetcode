class Solution {
public:
    int reverse(int x) {
        long long int rev = 0;
        while(x>0){
            if(rev>INT_MAX/10 || rev<INT_MIN/10) {
                return 0;
            }
            int last = x%10;
            rev = rev*10+last;
            x = x/10;
        }

        while(x<0){
            if(rev>INT_MAX/10 || rev<INT_MIN/10) {
                return 0;
            }
            int last = x%10;
            rev = rev*10+last;
            x = x/10;
        }
        return rev;
        
    }
};