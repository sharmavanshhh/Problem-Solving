class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low <= high){
            long long sqrt = low + (high - low) / 2;
            if(sqrt * sqrt == num){
                return true;
            }
            else if(sqrt * sqrt < num){
                low = sqrt + 1;
            }
            else{
                high = sqrt - 1;
            }
        }
        return false;
    }
};