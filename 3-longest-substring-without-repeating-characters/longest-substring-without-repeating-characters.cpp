class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int p=0;
        int q=0;
        int ans=0;
        while(q<s.size()){
              m[s[q]]++;
         
           
            while(m[s[q]]>1){
                m[s[p]]--;
                p++;
            }
           ans=max(ans,q-p+1);
           q++;

        }
   return ans; }
};