class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = nums[n-1];
        for(int i=1; i<n; i++){
            if(abs(nums[i] - nums[i-1]) < low){
                low = abs(nums[i] - nums[i-1]);
            }
        }
        int high = nums[n-1] - nums[0];

        while(low < high){
            int mid = low + (high - low) / 2;
            int pairs = possiblePairs(nums, mid);
            if(pairs < k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    int possiblePairs(vector<int>& nums, int x){
        int n = nums.size();
        int pairs = 0;
        int i = 0;
        for(int j=1; j<n; j++){
            while(nums[j] - nums[i] > x){
                i++;
            }
            pairs += (j-i);
        }
        return pairs;

    }
};