class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (except first bit)
        for (int i = s.size() - 1; i > 0; i--) {
            
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                // Odd → add 1 then divide by 2
                steps += 2;
                carry = 1;
            } else {
                // Even → divide by 2
                steps += 1;
            }
        }

        // If carry remains at MSB
        return steps + carry;
    }
};