class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Brute Force - [O(n)]
        // int i = 0;
        // while(i + 1 < arr.size() && arr[i] < arr[i + 1]){
        //     i++;
        // }
        // return i;

        // Optimal Solution - Binary Search [O(log n)]
        int low = 0;
        int high = arr.size() - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(arr[mid] < arr[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};