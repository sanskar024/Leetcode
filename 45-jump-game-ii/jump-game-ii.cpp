class Solution {
public:
int solve(int idx,vector<int>&nums, vector<int>&dp){
    if(idx>=nums.size()-1)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int mini=INT_MAX;
    for(int j=idx+1;j <= min((int)nums.size() - 1, idx + nums[idx]);j++){
       int steps = solve(j, nums, dp);

            if (steps != INT_MAX) {
                mini = min(mini, 1 + steps);
            }
    }
    return dp[idx]=mini;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
    
        return solve(0,nums,dp);
    }
};