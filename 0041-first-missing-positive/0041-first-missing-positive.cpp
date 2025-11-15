class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long n = nums.size();
        long long i = 0;
        while(i < n){
            long long index = nums[i] - 1;
            if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[index]){
                swap(nums[i], nums[index]);
            }
            else{
                i++;
            }
        }

        for(int k=0; k<n; k++){
            if(nums[k] != k + 1){
                return k+1;
            }
        }

        return n+1;
    }
};