class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++){
            if(isPrime(setBits(i))){
                ans++;
            }
        }
        return ans;
    }

    int setBits(int n){
        int count = 0;
        while(n > 0){
            n = n & n - 1;
            count++;
        }
        return count;
    }

    bool isPrime(int n){
        if(n < 2) return false;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        
        return true;
    }
};