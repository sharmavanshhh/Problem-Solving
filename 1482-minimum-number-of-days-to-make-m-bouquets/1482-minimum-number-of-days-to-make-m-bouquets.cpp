class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low < high){
            int mid = low + (high - low) / 2;

            int bouquets = canMake(bloomDay, k, mid);

            if(bouquets < m) low = mid + 1;
            else high = mid;
        }

        return low;
    }

    int canMake(vector<int>& bloomDay, int k, int days){
        int bouquet = 0;
        int flowers = 0;

        for(int d : bloomDay){
            if(d <= days){
                flowers++;
                if(flowers == k){
                    bouquet++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }

        return bouquet;
    }
};