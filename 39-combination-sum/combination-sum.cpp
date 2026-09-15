class Solution {
public:
vector<vector<int>>ans;
void solve(int i,int t,vector<int>curr,vector<int>& can){
    if(i==can.size()||t<0){
        if(t==0){
            ans.push_back(curr);
        }
         return;
    }
    curr.push_back(can[i]);
    solve(i,t-can[i],curr,can);
    curr.pop_back();
    solve(i+1,t,curr,can);
}
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<int>curr;
        solve(0,t,curr,can);
   return ans; }
};