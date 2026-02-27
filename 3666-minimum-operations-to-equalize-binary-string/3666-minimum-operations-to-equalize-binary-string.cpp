#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int start = 0;
        for(char c : s)
            if(c == '0') start++;
        
        if(start == 0) return 0;
        
        vector<bool> visited(n+1, false);
        set<int> evenSet, oddSet;
        
        for(int i = 0; i <= n; i++) {
            if(i % 2 == 0) evenSet.insert(i);
            else oddSet.insert(i);
        }
        
        queue<pair<int,int>> q;
        q.push({start, 0});
        visited[start] = true;
        
        if(start % 2 == 0) evenSet.erase(start);
        else oddSet.erase(start);
        
        while(!q.empty()) {
            auto [z, steps] = q.front();
            q.pop();
            
            int L = max(0, k - (n - z));
            int R = min(k, z);
            
            int newL = z + k - 2*R;
            int newR = z + k - 2*L;
            
            int parity = (z + k) % 2;
            set<int>& targetSet = (parity == 0 ? evenSet : oddSet);
            
            auto it = targetSet.lower_bound(newL);
            
            while(it != targetSet.end() && *it <= newR) {
                int nextZ = *it;
                it = targetSet.erase(it);
                
                if(nextZ == 0)
                    return steps + 1;
                
                visited[nextZ] = true;
                q.push({nextZ, steps + 1});
            }
        }
        
        return -1;
    }
};