class Solution {
public:
    bool judgeSquareSum(int x) {
        long long left = 0;
        long long right = (long long)sqrt(x);

        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == x) {
                return true;
            } else if (sum < x) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};
