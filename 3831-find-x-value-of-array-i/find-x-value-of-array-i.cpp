class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> next(k, 0);

            // Subarray consisting only of x
            next[x % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int nr = (1LL * r * x) % k;
                next[nr] += dp[r];
            }

            dp = next;

            // Add all subarrays ending here
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};