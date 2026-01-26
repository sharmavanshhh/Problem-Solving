class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()){
            return -1;
        }
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            int bouquets = possibleBouquets(bloomDay, mid, k);

            if (bouquets < m) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int possibleBouquets(vector<int>& bloomDays, int days, int k) {
        int bouquets = 0;
        int flowers = 0;
        for (int d : bloomDays) {
            if (d <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets;
    }
};