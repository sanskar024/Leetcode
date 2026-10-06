class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        stack<int> st;
        vector<int> ans;
        
        bool alive = true;

        for(int i = 0; i < ass.size(); i++) {
            alive = true;

            if(!st.empty() && ass[i] < 0 && st.top() > 0) {

                while(!st.empty() && st.top() > 0) {

                    if(st.top() < -ass[i]) {
                        st.pop();
                    }
                    else if(st.top() == -ass[i]) {
                        st.pop();
                        alive = false;
                        break;
                    }
                    else {
                        alive = false;
                        break;
                    }
                }
            }

            if(alive)
                st.push(ass[i]);
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};