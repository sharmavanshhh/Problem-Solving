class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = 0;
        while(low <= high){
            long long sqrt = low + (high - low) / 2;
            if(sqrt * sqrt == x){
                return sqrt;
            }
            else if(sqrt * sqrt < x){
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