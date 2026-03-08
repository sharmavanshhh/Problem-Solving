class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> binary(nums.begin(), nums.end());

        for(string s : binary) cout << s << " ";

        int len = nums[0].size();
        string ans = "";
        backtrack(nums, 0, len, "", binary, ans);

        return ans;
    }

    void backtrack(vector<string>&nums, int size, int len, string curr, set<string>& binary, string& ans){
        if(ans != "") return;

        if(size == len){
            if(!binary.count(curr)) ans = curr;
            return;
        }
        backtrack(nums, size + 1, len, curr + '0', binary, ans);
        backtrack(nums, size + 1, len, curr + '1', binary, ans);
        // curr.pop_back();
    }
};