class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int p=n-1;
        string ans="";
        bool start=false;
        string curr="";
        for(int i=n-1;i>=0;i--){
            if(start==false&&s[i]!=' '){
                start=true;
                curr+=s[i];
            }
            else if(s[i]==' '&&start==true){
                reverse(curr.begin(),curr.end());
                if (!ans.empty())
    ans += ' ';
                ans+=curr;
             
                start=false;
                curr="";
                
            }
            else if(start==true&&s[i]!=' '){
                curr+=s[i];
            }
        }
           reverse(curr.begin(),curr.end());
          if (!curr.empty()) {
            if (!ans.empty())
                ans += ' ';

            ans += curr;
        }
   return ans; }
};