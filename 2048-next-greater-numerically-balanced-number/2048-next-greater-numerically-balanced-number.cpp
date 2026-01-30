class Solution {
public:
    int nextBeautifulNumber(int n) {
        int x = n + 1;

        while(true){
            if(isBalanced(x)){
                return x;
            }
            x++;
        }
    }

    bool isBalanced(int x){
        vector<int> freq(10,0);

        while(x){
            freq[x%10]++;
            x/=10;
        }

        for(int d=0; d<=9; d++){
            if(freq[d] != 0 && freq[d] != d){
                return false;
            }
        }
        return true;
    }

};