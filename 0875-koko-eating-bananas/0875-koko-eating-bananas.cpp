class Solution {
public:
    bool eatable(vector<int>& piles, long long speed, int h) {
        long long totalHours = 0;
        for(int bananas : piles){
            totalHours += ceil((double)bananas / speed);

        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(eatable(piles, mid, h)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
