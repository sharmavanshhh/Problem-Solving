class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        long long first = 0;
        long long last = 0;
        long long count = 0;
        sum = nums[0];
        while(last < nums.size() && first < nums.size()){
            if(sum == k){
                count++;
                last++;
            }
            if(sum < k){
                last++;
                sum += nums[last];
            }
            if(sum > k){
                first++;
                sum -= nums[first];
            }
        }
        return count;
    }
};