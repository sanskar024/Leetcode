class Solution {
public:
int solve(int i,int j,int n,vector<int>&cuts,vector<vector<int>>&dp){
    if(j-i<=1)return 0;
            if (dp[i][j] != -1)
            return dp[i][j];

int mini=INT_MAX;
  for(int k=i+1;k<=j-1;k++){
    int cost=cuts[j]-cuts[i]+solve(i,k,n,cuts,dp)+solve(k,j,n,cuts,dp);
    mini=min(mini,cost);
  }
  return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
         cuts.insert(cuts.begin(), 0);
              cuts.push_back(n);
        int m = cuts.size();
 
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
    return    solve(0,cuts.size()-1,n,cuts,dp);
    }
};   