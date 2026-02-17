class Solution {
public:

    void backtracking(int turnedOn, int index, int hours, int minutes, vector<string>& ans){
        if(turnedOn == 0){
            if(hours < 12 && minutes < 60){
                string time = to_string(hours) + ":";
                if(minutes < 10){
                    time += "0";
                }
                time += to_string(minutes);
                ans.push_back(time);
            }
            return;
        }

        for(int i=index; i<10; i++){
            // hours
            if(i<4){
                backtracking(turnedOn-1, i+1, hours + (1 << i), minutes, ans);
            }
            // minutes
            else{
                backtracking(turnedOn-1, i+1, hours, minutes + (1 << (i - 4)), ans);
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        backtracking(turnedOn, 0, 0, 0, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};