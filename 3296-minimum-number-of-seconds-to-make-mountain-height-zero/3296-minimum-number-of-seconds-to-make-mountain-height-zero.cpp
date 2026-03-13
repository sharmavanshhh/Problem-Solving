class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long high = 1e18;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long reduced = destroy(mid, workerTimes);

            if(reduced >= mountainHeight){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }

    long long destroy(long long sec, vector<int>& workerDays){
        long long total = 0;

        for(int t : workerDays){
            long long val = sec / t;
            long long k = (sqrt(1 + 8LL * val) - 1) / 2;

            total += k;
        }

        return total;
    }
};