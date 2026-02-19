class Solution {
public:
    string getPermutation(int n, int k) {
        vector<long long> fact = {
            1,     // 1!
            2,     // 2!
            6,     // 3!
            24,    // 4!
            120,   // 5!
            720,   // 6!
            5040,  // 7!
            40320, // 8!
            362880 // 9!
        };

        int groupSize = fact[n - 1] / n;
        int groups = fact[n - 1] / groupSize;
        int groupNo = (k + groupSize - 1) / groupSize;
        int pos = k;
        if (pos > groupSize) {
            while (pos > groupSize) {
                pos -= groupSize;
            }
        }
        cout << groupSize << " " << groups << " " << groupNo << " " << pos
             << endl;
        int num = groupNo;
        for (int i = 1; i <= n; i++) {
            if (i == groupNo)
                continue;
            num *= 10;
            num += i;
        }
        cout << num << endl;

        string x = to_string(num);
        for (int i = 1; i < pos; i++) {
            next_permutation(x.begin() + 1, x.end());
        }

        return x;
        // vector<string> perm;
        // backtrack(perm, x, groupSize, 0);
        // for (string x : perm)
        //     cout << x << " ";

        // // if(pos == 0) return perm[pos];
        // sort(perm.begin(), perm.end());
        // return perm[pos - 1];
        // return "";
    }

    void backtrack(vector<string>& perm, string& str, int y, int index) {
        if (perm.size() == y)
            return;
        if (index == str.size()) {
            perm.push_back(str);
            return;
        }
        for (int i = index; i < str.size(); i++) {
            swap(str[index], str[i]);
            backtrack(perm, str, y, index + 1);
            swap(str[index], str[i]);

            if (perm.size() == y)
                return; // early stop
        }
    }
};