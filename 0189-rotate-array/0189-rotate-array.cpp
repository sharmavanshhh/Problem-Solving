class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       /*Brute Force Solution - O(nk)*/
    //    int n = nums.size();
    //    int p = 1;
    //    while(p <= k){
    //     int temp = nums[n-1];
    //     for(int i=n-1; i>0; i--){
    //         nums[i] = nums[i-1];
    //     }
    //     nums[0] = temp;
    //     p++;
    //    } 

    /*Optimal Solution - O(n)*/
    int n = nums.size();
    k = k % n;
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.begin(), nums.end());
    }
};