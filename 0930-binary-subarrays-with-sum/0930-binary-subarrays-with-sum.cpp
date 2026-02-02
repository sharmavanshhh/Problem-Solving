class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // unordered_map<int, int> mp;
        // mp[0] = 1;
        // int sum = 0;
        // int count = 0;
        // for(int x : nums){
        //     sum += x;
        //     int need = sum - goal;
        //     if(mp.count(need)){
        //         count += mp[need];
        //     }
        //     mp[sum]++;
        // }
        // return count;

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left++];
            }

            count += (right - left + 1);
        }

        return count;
    }
};