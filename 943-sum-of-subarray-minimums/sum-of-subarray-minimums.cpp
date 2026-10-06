class Solution {
public:
    vector<int> getls;
    vector<int> getrs;

    void solvels(vector<int>& arr) {
        stack<int> st;

        for(int i = 0; i < arr.size(); i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty())
                getls[i] = -1;
            else
                getls[i] = st.top();

            st.push(i);
        }
    }

    void solvers(vector<int>& arr) {
        stack<int> st;

        for(int i = arr.size() - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty())
                getrs[i] = arr.size();
            else
                getrs[i] = st.top();

            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {

        int M = 1e9 + 7;
        long long sum = 0;

        int n = arr.size();

        getls.resize(n);
        getrs.resize(n);

        solvels(arr);
        solvers(arr);

        for(int i = 0; i < n; i++) {

            long long ls = i - getls[i];
            long long rs = getrs[i] - i;

            long long contribution = ls * rs * arr[i];

            sum = (sum + contribution) % M;
        }

        return sum;
    }
};