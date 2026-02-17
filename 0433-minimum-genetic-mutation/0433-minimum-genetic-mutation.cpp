class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());

        if (!st.count(endGene)) return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push(startGene);
        visited.insert(startGene);

        int steps = 0;
        vector<char> genes = {'A', 'C', 'G', 'T'};

        while(!q.empty()){
            int size = q.size();

            while(size > 0){
                string curr = q.front();
                q.pop();
                size--;

                if(curr == endGene){
                    return steps;
                }

                for(int i = 0; i < 8; i++){
                    char original = curr[i];

                    for(char ch : genes){
                        curr[i] = ch;

                        if(!visited.count(curr) && st.count(curr)){
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }

                    curr[i] = original;
                }
            }
            steps++;
        }
        return -1;
    }
};