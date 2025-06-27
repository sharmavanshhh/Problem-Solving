class Solution {
public:

    int binarySearch(vector<int>& arr, int key, bool first){
        int low = 0;
        int high = arr.size()-1;
        int result = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == key){
                result = mid;
                if(first){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(key < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};