class Solution {
public:

    int minCut(string s) {

        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Precompute all palindromes
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum number of palindrome pieces
        // needed to partition s[i...n-1]
        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            int ans = INT_MAX;

            for (int j = i; j < n; j++) {

                if (pal[i][j]) {

                    int cost = 1 + dp[j + 1];

                    ans = min(ans, cost);
                }
            }

            dp[i] = ans;
        }

        // dp[0] = number of palindrome pieces
        // cuts = pieces - 1
        return dp[0] - 1;
    }
};