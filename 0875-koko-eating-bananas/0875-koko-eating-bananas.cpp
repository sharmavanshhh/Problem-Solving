class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long hours = isEatable(piles, mid);

            if(hours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

    long long isEatable(vector<int>& piles, int speed){
        long long totalHours = 0;
        for(int banana : piles){
            totalHours += (banana + speed - 1) / speed;
        }
        return totalHours;
    }
};