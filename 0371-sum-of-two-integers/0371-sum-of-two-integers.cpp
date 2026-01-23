class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            uint32_t carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};