class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Cycle Sort

        // int i = 0;
        // int n = nums.size();
        // while(i < n){
        //     int index = nums[i];
        //     if(nums[i] < n && nums[i] != nums[index]){
        //         swap(nums[i], nums[index]);
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // for(int k=0; k<n; k++){
        //     if(nums[k] != k){
        //         return k;
        //     }
        // }
        // return n;

        // Bit Manipulation Trick
        int n = nums.size();
        int xorr = n;
        for(int i = 0; i < n; i++){
            xorr ^= i;
            xorr ^= nums[i];
        }
        return xorr;
    }
};