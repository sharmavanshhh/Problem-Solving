class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;

        long long digitLength = 1;
        long long count = 9;
        long long start = 1;

        while(n > digitLength * count){
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        long long number = start + (n - 1) / digitLength;

        int digitIndex = (n - 1) % digitLength;

        string s = to_string(number);

        return s[digitIndex] - '0';
    }   
};