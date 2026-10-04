class Solution {
public:
int t[101][101];
bool solve(int idx,int open,string s,int n){
 if(idx==n){
    return open==0;
     }
     bool isValid=false;
     if(t[idx][open]!=-1)return t[idx][open];
     if(s[idx]=='('){
        isValid=solve(idx+1,open+1,s,n);
     }
     else if(s[idx]=='*'){
     isValid = solve(idx + 1, open + 1, s, n) ||
          solve(idx + 1, open, s, n);

    if(open > 0) {
    isValid = isValid || solve(idx + 1, open - 1, s, n);
}
     }
     else if(s[idx]==')'){
        if(open>0){
            isValid=solve(idx+1,open-1,s,n);
        }
     }
     return t[idx][open]=isValid;
}
    bool checkValidString(string s) {
        int n=s.size();
        memset(t, -1, sizeof(t));
        return solve(0,0,s,n);
    }
};