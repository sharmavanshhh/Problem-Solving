class Solution {
public:

    bool shippable(vector<int>& weights, int capacity, int days){
        int currentWeight = 0;
        int day = 1;

        for(int w : weights){
            if(currentWeight + w > capacity){
                day++;
                currentWeight = 0;
            }
            currentWeight += w;
        }
        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = weights[0];
        int high = 0;
        for(int i=0; i<weights.size(); i++){
            if(low < weights[i]){
                low = weights[i];
            }
            high += weights[i];
        }

        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(shippable(weights, mid, days)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;    
    }
};