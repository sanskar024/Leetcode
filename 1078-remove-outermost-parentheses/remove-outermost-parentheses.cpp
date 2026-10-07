class Solution {
public:
    string removeOuterParentheses(string s) {
        int dis=0;
        string ans="";
        int last=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')dis++;
            else dis--;
            if(dis==0){
                ans=ans+s.substr(last+1,i-1-last);
                last=i+1;
            }
        }
   return ans; }
};