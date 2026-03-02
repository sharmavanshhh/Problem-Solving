class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;

        // XOR all numbers
        for(int a : nums){
            xorr = xorr ^ a;
        }

        // Now, xorr = unique1 ^ unique2
        // Turn on the righmost setbit of xorr
        long long rightmost_bit = xorr & (-xorr);

        // Now this rightmost setbit will differ 0/1 in the unique numbers
        // Divide the numbers in two groups based on this bit as 0/1
        // Each group will contain duplicates and one unique
        // Doing xorr within each group will eliminate the duplicates
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
        return {g1,g2};
    }
};