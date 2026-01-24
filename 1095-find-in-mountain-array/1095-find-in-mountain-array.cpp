/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            int next = mountainArr.get(mid + 1);
            if (val < next)
                low = mid + 1;
            else
                high = mid;
        }
        int peak = low;

        int leftSearch = binarySearch(mountainArr, target, 0, peak, true);
        if(leftSearch != -1){
            return leftSearch;
        }
        
        return binarySearch(mountainArr, target, peak + 1, n - 1, false);
    }

    int binarySearch(MountainArray& mountainArr, int target, int low, int high, bool asc){
        while(low <= high){
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);

            if(val == target){
                return mid;
            }
            else if(val < target){
                if(asc){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            else{
                if(asc){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};