class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;

        while (!st.empty() && a < 0 && st.top() > 0) {
            if (st.top() < -a) {
                st.pop();  // top explodes, continue checking
            } else if (st.top() == -a) {
                st.pop();  // both explode
                destroyed = true;
                break;
            } else {
                destroyed = true;  // current one explodes
                break;
            }
        }

        if (!destroyed) {
            st.push(a);
        }
    }

    // Convert stack to vector
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }

    return result;
    }
};