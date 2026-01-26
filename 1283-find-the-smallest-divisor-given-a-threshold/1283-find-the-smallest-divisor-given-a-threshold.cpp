class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high){
            int mid = low + (high - low) / 2;

            int sum = divide(nums, mid);
            
            if(sum > threshold){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    int divide(vector<int>& nums, int divisor){
        int sum = 0;
        for(int n : nums){
            sum += (n + divisor - 1) / divisor;
        }
        return sum;
    }
};