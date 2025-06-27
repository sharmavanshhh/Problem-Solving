class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long temp = x;
        long rev = 0;
        while(x > 0){
            int num = x % 10;
            rev = rev * 10 + num;
            x /= 10;
        }
        return (rev == temp);
    }
};