class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high){
            int mid = low + (high - low) / 2;
            int ops = maxOps(nums, mid, maxOperations);

            if(ops > maxOperations) low = mid + 1;
            else high = mid;
        }

        return low;
    }

    int maxOps(vector<int>& nums, int p, int maxOps){
        int ops = 0;
        for(int x : nums){
            ops += (x - 1) / p;
            if(ops > maxOps) break;
        }
        return ops;
    }
};