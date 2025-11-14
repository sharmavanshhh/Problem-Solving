class Solution {
public:
    int getSum(int a, int b) {
        uint32_t carry = a & b;
        int sum = a ^ b;
        int actualCarry = carry << 1;
        
        while(carry != 0){
            carry = sum & actualCarry;
            sum = sum ^ actualCarry;
            actualCarry = carry << 1;
        }

        return sum;
    }
};