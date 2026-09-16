class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int open, int n, int k,
              vector<vector<vector<int>>> &dp) {

        // All segments have been completed
        if (k == 0 && open == 0)
            return 1;

        // No more points
        if (i == n)
            return 0;

        if (k < 0)
            return 0;

        if (dp[i][k][open] != -1)
            return dp[i][k][open];

        long long take = 0;
        long long notake = 0;

        if (open == 1) {

            // Close current segment at i
            take = solve(i, 0, n, k - 1, dp);

            // Extend current segment
            notake = solve(i + 1, 1, n, k, dp);

        } else {

            // Start a segment at i
            take = solve(i + 1, 1, n, k, dp);

            // Skip i
            notake = solve(i + 1, 0, n, k, dp);
        }

        return dp[i][k][open] = (take + notake) % MOD;
    }

    int numberOfSets(int n, int k) {

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(
                k + 1,
                vector<int>(2, -1)
            )
        );

        return solve(0, 0, n, k, dp);
    }
};