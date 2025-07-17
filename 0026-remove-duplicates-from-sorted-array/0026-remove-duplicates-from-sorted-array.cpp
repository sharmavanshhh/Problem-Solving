class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // slow pointer

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;                // move slow pointer
                nums[i] = nums[j];  // overwrite duplicate
            }
        }

        return i + 1; // new length of array without duplicates
    }
};
