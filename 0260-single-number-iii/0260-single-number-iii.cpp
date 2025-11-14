class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        
        // XOR All
        for(int i=0; i<nums.size(); i++){
            xorr = xorr ^ nums[i];
        }

        // Turn on rightmost set bit
        long long rightmost_bit = (xorr ^ xorr-1) & xorr;

        // Divide in groups
        int g1 = 0;
        int g2 = 0;
        for(int x : nums){
            if(x & rightmost_bit){
                g1 = g1 ^ x;
            }
            else{
                g2 = g2 ^ x;
            }
        }

        return {g1, g2};
    }
};