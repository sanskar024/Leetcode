class Solution {
public:
bool solve(int bal,int i,int j,vector<vector<char>>& grid, vector<vector<vector<int>>>&dp){
if(i >= grid.size() || j >= grid[0].size())
    return false;
if(grid[i][j]=='(')bal++;
else bal--;
if(bal<0)return false;
 if(dp[i][j][bal]!=-1)return dp[i][j][bal];
if(i==grid.size()-1&&j==grid[0].size()-1){
    if(bal==0)return true;
    else return false;
}
bool right=solve(bal,i,j+1,grid,dp);
bool down=solve(bal,i+1,j,grid,dp);
return dp[i][j][bal]=(right||down);
}
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<int>>>dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m+n,-1)
            )
        );
        return solve(0,0,0,grid,dp);
    }
};