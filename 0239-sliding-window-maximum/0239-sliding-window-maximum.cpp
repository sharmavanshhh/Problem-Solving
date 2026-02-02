class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // stores indices
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            // 1. Remove out of window index
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Push current index
            dq.push_back(i);

            // 4. Store result when window is ready
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
