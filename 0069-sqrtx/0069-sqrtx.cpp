class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = 0;
        while(low <= high){
            int sqrt = low + (high - low) / 2;
            if((long)sqrt*sqrt == x){
                return sqrt;
            }
            else if((long)sqrt*sqrt <= x){
                ans = sqrt;
                low = sqrt + 1;
            }
            else{
                high = sqrt - 1;
            }
        }

        return ans;
    }
};