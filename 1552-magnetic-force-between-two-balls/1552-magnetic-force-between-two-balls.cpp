class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();

        while(low <= high){
            int mid = low + (high - low) / 2;

            int balls = canPlace(position, mid);

            if(balls >= m) low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }

    int canPlace(vector<int>& position, int force){
        int balls = 1;
        int last = position[0];

        for(int i = 1; i < position.size(); i++){
            if(position[i] - last >= force){
                balls++;
                last = position[i];
            }
        }
        return balls;
    }
};