class Solution {
public:
vector<string>ans;
int bal=0;
int maxl=0;
void solve(int i,string &s,string &curr,int bal){
  
if(i==s.size()){
   if(bal == 0) {

                if(curr.size() > maxl) {
                    maxl = curr.size();
                    ans.clear();
                    ans.push_back(curr);
                }
                else if(curr.size() == maxl) {
                    ans.push_back(curr);
                }
            }
    return;
}
if(s[i]=='(')bal++;
else if(s[i]==')')bal--;

if(bal>=0){
    curr.push_back(s[i]);
    solve(i+1,s,curr,bal);
    curr.pop_back();
    }
if(s[i] == '(')
    bal--;
else if(s[i] == ')')
    bal++;
if(s[i]=='('||s[i]==')')solve(i+1,s,curr,bal);
}
    vector<string> removeInvalidParentheses(string s) {
        string curr="";
        solve(0,s,curr,0);
            sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};