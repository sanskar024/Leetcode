class Solution {
public:

void solve(int idx,int k,int n, vector<vector<int>>&ans, vector<int>&curr){
    if(k==0){
        if(n==0){
        ans.push_back(curr);
    }
     return;
    }
   
    for(int i=idx;i<=9;i++){
        curr.push_back(i);
        solve(i+1,k-1,n-i,ans,curr);
        curr.pop_back();
    
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(1,k,n,ans,curr);
        return ans;
    }
};