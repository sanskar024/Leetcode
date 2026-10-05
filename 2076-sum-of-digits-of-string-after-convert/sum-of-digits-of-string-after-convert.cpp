class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";

        for (char c : s) {
            int val = c - 'a' + 1;
            ans += to_string(val);
        }

        int x = 0;

        for (char c : ans) {
            x += c - '0';
        }

        k--;  // first digit-sum already performed above

        while (k > 0) {
            int next = 0;

            while (x > 0) {
                next += x % 10;
                x /= 10;
            }

            x = next;
            k--;
        }

        return x;
    }
};