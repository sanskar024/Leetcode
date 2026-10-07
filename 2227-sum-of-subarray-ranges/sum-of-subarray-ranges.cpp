class Solution {
public:
    vector<int> lge, rge, lse, rse;

    void func1(vector<int>& nums) {
        int n = nums.size();

        stack<int> st1;
        stack<int> st2;

        for (int i = n - 1; i >= 0; i--) {

            // Right Greater OR Equal
            while (!st1.empty() && nums[st1.top()] < nums[i]) {
                st1.pop();
            }

            rge[i] = st1.empty() ? n : st1.top();
            st1.push(i);


            // Right Smaller OR Equal
            while (!st2.empty() && nums[st2.top()] > nums[i]) {
                st2.pop();
            }

            rse[i] = st2.empty() ? n : st2.top();
            st2.push(i);
        }
    }

    void func2(vector<int>& nums) {
        int n = nums.size();

        stack<int> st3;
        stack<int> st4;

        for (int i = 0; i < n; i++) {

            // Left Greater (STRICT)
            while (!st3.empty() && nums[st3.top()] <= nums[i]) {
                st3.pop();
            }

            lge[i] = st3.empty() ? -1 : st3.top();
            st3.push(i);


            // Left Smaller (STRICT)
            while (!st4.empty() && nums[st4.top()] >= nums[i]) {
                st4.pop();
            }

            lse[i] = st4.empty() ? -1 : st4.top();
            st4.push(i);
        }
    }

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        lge.resize(n);
        rge.resize(n);
        lse.resize(n);
        rse.resize(n);

        func1(nums);
        func2(nums);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long maxCount =
              (i - lge[i]) * (rge[i] - i);

            long long minCount =
              (i - lse[i]) * (rse[i] - i);

            ans +=  nums[i] * maxCount;
            ans -=  nums[i] * minCount;
        }

        return ans;
    }
};