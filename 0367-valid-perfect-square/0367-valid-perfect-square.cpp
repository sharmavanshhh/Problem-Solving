class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low <= high){
            int sqrt = low + (high - low) / 2;
            long long temp = (long long)sqrt * (long long)sqrt;
            if(temp == num) return true;
            else if(temp < num){
                low = sqrt + 1;
            }
            else high = sqrt - 1;
        }
        return false;
    }
};