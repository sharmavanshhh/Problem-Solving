class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> busy;

        vector<int> count(n, 0);

        for(int i = 0; i < n; i++)
            freeRooms.push(i);

        for(auto &m : meetings){

            long long start = m[0];
            long long end   = m[1];

            // free rooms
            while(!busy.empty() && busy.top().first <= start){
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if(!freeRooms.empty()){
                int room = freeRooms.top();
                freeRooms.pop();
                busy.push({end, room});
                count[room]++;
            }
            else{
                auto [time, room] = busy.top();
                busy.pop();

                long long duration = end - start;
                busy.push({time + duration, room});
                count[room]++;
            }
        }

        int maxRoom = 0;
        for(int i = 1; i < n; i++){
            if(count[i] > count[maxRoom])
                maxRoom = i;
        }

        return maxRoom;
    }
};
