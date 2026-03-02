class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        // Check power of 2
        if((n & (n - 1)) != 0) return false;
        // Check even position bit
        if((n & 0x55555555) == 0) return false;
        return true;

        // if(n < 1) return false;
        // while(n % 4 == 0) n /= 4;
        // return n == 1;    
    }
};