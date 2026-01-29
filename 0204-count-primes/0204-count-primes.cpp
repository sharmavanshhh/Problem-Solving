class Solution {
public:
    bool checkPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimes(int n) {
        if(n < 2) return 0;
        
        int count = 0;

        bool* arr = new bool[n + 1];
        arr[0] = false;
        arr[1] = false;

        for (int i = 2; i <= n; i++) {
            arr[i] = true;
        }

        for(int i=2; i*i<=n; i++){
            if(arr[i] == true){
                for(int j=i*i; j<=n; j+=i){
                    arr[j] = false;
                }
            }
        }

        for(int i=2; i<n; i++){
            if(arr[i] == true){
                count++;
            }
        }

        return count;
    }
};
