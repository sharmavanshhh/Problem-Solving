class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low < high){
            int mid = low + (high - low) / 2;

            int ops = possibleOps(nums, mid);

            if(ops > maxOperations){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    int possibleOps(vector<int>& nums, int balls){
        long long ops = 0;

        for(int x : nums){
            ops += (x - 1) / balls;
        }

        return (int)ops;
    }
};