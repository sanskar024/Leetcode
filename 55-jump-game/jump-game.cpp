class Solution {
public:
bool solve(int idx,vector<int>& nums, vector<int>&dp){
    if(idx>=nums.size()-1)return true;
    if(dp[idx]!=-1)return dp[idx];
    for(int i=1;i<=nums[idx];i++){
        if(solve(idx+i,nums,dp))return true;
    }
    return dp[idx]=false;
}
    bool canJump(vector<int>& nums) {
       
int n=nums.size();
 vector<int>dp(n,-1);
return solve(0,nums,dp);

    }
};