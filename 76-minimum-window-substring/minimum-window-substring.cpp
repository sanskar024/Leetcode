class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(128, 0);
        vector<int> v2(128, 0);

        if (s.size() < t.size())
            return "";

        string ans = "";
        int minLen = INT_MAX;

        for (int i = 0; i < t.size(); i++) {
            v[t[i]]++;
        }

        int p = 0;
        int q = 0;
        int count = t.size();
        int start=-1;

        while (q < s.size()) {

            v2[s[q]]++;

            if (v2[s[q]] <= v[s[q]]) {
                count--;
            }

            while (count == 0) {

                // Check current valid window
                if (q - p + 1 < minLen) {
                    minLen = q - p + 1;
                start=p;
                }

                // Remove left character
                if (v2[s[p]] <= v[s[p]]) {
                    count++;
                }

                v2[s[p]]--;
                p++;
            }

            q++;
        }
if(start==-1)return "";
        return s.substr(start,minLen);;
    }
};