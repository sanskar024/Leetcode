class Solution {
public:
int minOperations(string s) {
int n = s.size();

    string sorted = s;
    sort(sorted.begin(), sorted.end());

    // 1. Already sorted
    if (s == sorted) return 0;

    // 2. Length is 2
    if (n == 2) return -1;

    // 3. Smallest at first OR largest at last
    if (s[0] == sorted[0] || s[n - 1] == sorted[n - 1])
        return 1;

    // 4. Unique largest at first AND unique smallest at last
    if (s[0] == sorted[n - 1] &&
        s[n - 1] == sorted[0] &&
        count(s.begin(), s.end(), s[0]) == 1 &&
        count(s.begin(), s.end(), s[n - 1]) == 1)
        return 3;

    // 5. Otherwise
    return 2;
}

};