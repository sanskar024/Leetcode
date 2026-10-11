class Solution {
public:
    int dp[101][101];
  bool ans = false;
    bool solve(string &s, int i, int open) {

        if (open < 0)
            return false;

        if (i == s.size())
            return open == 0;

        if (dp[i][open] != -1)
            return dp[i][open];

      

        if (s[i] == '(') {
            ans = solve(s, i + 1, open + 1);
        }

        else if (s[i] == ')') {
            ans = solve(s, i + 1, open - 1);
        }

        else { // '*'

            // '*' = '('
            ans = solve(s, i + 1, open + 1)

                // '*' = empty
                || solve(s, i + 1, open)

                // '*' = ')'
                || solve(s, i + 1, open - 1);
        }

        return dp[i][open] = ans;
    }

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 0);
    }
};