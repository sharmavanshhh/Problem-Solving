class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp = "";
        
        for(int i = 0; i <= path.size(); i++) {
            if(i == path.size() || path[i] == '/') {
                
                if(temp == "" || temp == ".") {
                    // do nothing
                }
                else if(temp == "..") {
                    if(!st.empty()) st.pop_back();
                }
                else {
                    st.push_back(temp);
                }
                
                temp = "";
            }
            else {
                temp += path[i];
            }
        }
        
        string result = "";
        for(string dir : st) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};