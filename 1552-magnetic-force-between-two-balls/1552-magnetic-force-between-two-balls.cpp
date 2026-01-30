class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();

        while(low <= high){
            int mid = low + (high - low) / 2;

            int balls = checkBalls(position, mid);

            if(balls >= m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }

    int checkBalls(vector<int>& position, int m){
        int last = position[0];
        int balls = 1;
        for(int i=1; i<position.size(); i++){
            if(position[i] - last >= m){
                balls++;
                last = position[i];
            }
        }
        return balls;
    }
};