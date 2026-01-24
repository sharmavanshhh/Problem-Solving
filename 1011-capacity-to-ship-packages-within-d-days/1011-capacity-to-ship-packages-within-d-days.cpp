class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;
            int numberOfDays = isShippable(weights, mid);

            if(numberOfDays <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

    int isShippable(vector<int>& weights, int capacity){
        int day = 1;
        int load = 0;
        for(int w : weights){
            if(load + w > capacity){
                day++;
                load = w;
            }
            else{
                load += w;
            }
        }
        return day;
    }
};