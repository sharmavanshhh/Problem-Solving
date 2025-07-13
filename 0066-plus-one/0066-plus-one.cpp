class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;     // No carry, just add and return
                return digits;
            }
            digits[i] = 0;        // Set to 0 and continue carry
        }
        
        // If we are here, all digits were 9 (e.g., 999 → 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
