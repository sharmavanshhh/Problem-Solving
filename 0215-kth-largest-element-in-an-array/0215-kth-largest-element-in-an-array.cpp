class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // for (int num : nums) {
    //     minHeap.push(num);
    //     if (minHeap.size() > k)
    //         minHeap.pop();
    // }
    // return minHeap.top();

        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }
        for(int i = 1; i < k; i++){
            pq.pop();
        }
        return pq.top();
    }
};