class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low < high){
            int mid = low + (high - low) / 2;

            int pieces = countPieces(nums, mid);

            if(pieces > k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    int countPieces(vector<int>& nums, int mid){
        int pieces = 1;
        int sum = 0;
        for(int x : nums){
            if(sum + x > mid){
                pieces++;
                sum = x;
            }
            else{
                sum += x;
            }
        }
        return pieces;
    }
};