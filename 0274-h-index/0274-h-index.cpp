class Solution {
public:
    int hIndex(vector<int>& citations) {

        /*Binary Search - [O(n log n)]*/

        // int n = citations.size();
        // int low = 0, high = n;
        // while (low <= high) {
        //     int mid = low + (high - low) / 2;
        //     int count = 0;
        //     for (int c : citations) {
        //         if (c >= mid)
        //             count++;
        //     }
        //     if (count >= mid)
        //         low = mid + 1;
        //     else
        //         high = mid - 1;
        // }
        // return high;

        /*Sorting Logic - [O(n log n)]*/
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int i=0; i<n; i++){
            if(citations[i] >= n-i){
                return n-i;
            }
        }
        return 0;
    }
};