class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;

            int splits = canSplit(nums, mid);

            if(splits <= k) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }

    int canSplit(vector<int>& nums, int maxSum){
        int split = 1;
        int currSum = 0;
        for(int x : nums){
            if(currSum + x > maxSum){
                split++;
                currSum = x;
            }
            else{
                currSum += x;
            }
        }
        return split;
    }
};