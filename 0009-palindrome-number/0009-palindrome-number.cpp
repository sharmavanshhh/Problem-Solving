class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x;
        long long rev = 0;
        while(x > 0){
            int rem = x % 10;
            rev = rev*10 + rem;
            x /= 10;
        }

        return (rev == temp);
    }
};