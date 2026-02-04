class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*Min Heap - O(n log k)*/
        // unordered_map<int, int> freq;
        // for(int x : nums){
        //     freq[x]++;
        // }
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        // for(auto &p : freq){
        //     minHeap.push({p.second, p.first});
        //     if(minHeap.size() > k){
        //         minHeap.pop();
        //     }
        // }
        // vector<int> ans;
        // while(!minHeap.empty()){
        //     ans.push_back(minHeap.top().second);
        //     minHeap.pop();
        // }
        // return ans;

        /*Bucket Sort - O(n)*/
        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto &p : freq){
            bucket[p.second].push_back(p.first);
        }
        vector<int> ans;
        for(int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--){
            for(int x : bucket[i]){
                ans.push_back(x);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};