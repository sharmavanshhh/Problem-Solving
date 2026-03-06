class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            int divisor = canDivide(nums, mid);

            if(divisor <= threshold) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }

    int canDivide(vector<int>& nums, int div){
        int sum = 0;
        for(int n : nums){
            sum += (n + div - 1) / div;
        }
        return sum;
    }
};