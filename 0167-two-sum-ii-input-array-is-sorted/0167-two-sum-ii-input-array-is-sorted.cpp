class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // vector<int> res;
        int low = 0;
        int high = numbers.size() - 1;
        while(low < high){
            long long sum = (long long)numbers[low] + (long long)numbers[high];
            if(sum == target){
                return {low+1, high+1};
            }
            if(sum < target){
                low++;
            }
            if(sum > target){
                high--;
            }
        }
        return {};
    }
};