class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);

        return {first, last};
    }

    int binarySearch(vector<int>& nums, int target, bool first){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                if(first){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};