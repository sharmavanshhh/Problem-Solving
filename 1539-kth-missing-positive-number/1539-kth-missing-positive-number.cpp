class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size();
        
        while(low < high){
            int mid = low + (high - low) / 2;
            int index = mid + 1;

            if(arr[mid] - index < k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low + k;
    }
};