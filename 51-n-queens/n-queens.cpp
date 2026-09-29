class Solution {
public:
vector<vector<string>>ans;
bool isvalid(int x,int y,vector<string>&v){
    int n=v.size();
    int i=x;
    int j=y;
        while(i>=0){
        if(v[i][j]=='Q')return false;
        i--;
    }
      i=x;
     j=y;
    while(i>=0&&j>=0){
        if(v[i][j]=='Q')return false;
        i--;
        j--;
    }
      i=x;
     j=y;
    while(i>=0&&j<n){
        if(v[i][j]=='Q')return false;
        i--;
        j++;
    }
    return true;

}
void solve(int i,int j,vector<string>&v,int n){
    if(i == n) {
    ans.push_back(v);
    return;
}
    for(int j=0;j<n;j++){
        if(isvalid(i,j,v)){
            v[i][j]='Q';
            solve(i+1,j,v,n);
            v[i][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n,string(n,'.'));
        solve(0,0,v,n);
      return ans;
    }
};