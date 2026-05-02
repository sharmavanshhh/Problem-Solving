class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(n == 0) return true;
        for(int i = 0; i < size; i++){
            if(flowerbed[i] == 1){
                continue;
            }
            if(flowerbed[i] == 0 && ((i == 0) || flowerbed[i-1] != 1) && ((i == size - 1) || flowerbed[i+1] != 1)){
                flowerbed[i] = 1;
                n -= 1;
            }
            if(n == 0) break;
        }
        return n == 0;
    }
};