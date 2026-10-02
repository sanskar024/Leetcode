class Solution {
public:
vector<string>ans;
void solve(string temp,int open,int close,int n){
if(temp.size()==2*n){
    ans.push_back(temp);
    return ;
}

if(open > 0) {
    solve(temp + '(', open - 1, close, n);
}

if(close > open) {
    solve(temp + ')', open, close - 1, n);
}


}
    vector<string> generateParenthesis(int n) {
        solve("", n, n,n);
    return ans;
    }
};