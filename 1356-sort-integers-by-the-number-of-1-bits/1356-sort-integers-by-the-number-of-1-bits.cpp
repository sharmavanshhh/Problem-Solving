class Solution {
public:
    int countBits(int num){
        int bits = 0;
        while(num){
            bits += (num & 1);
            num >>= 1;
        }
        return bits;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            int bitsA = countBits(a);
            int bitsB = countBits(b);
            
            if(bitsA == bitsB)
                return a < b;      // same bits → smaller number first
            
            return bitsA < bitsB;  // fewer bits first
        });

        return arr;
    }
};