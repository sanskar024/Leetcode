class Solution {
public:
 void solve(int i, vector<int>& nums, vector<int>& curr, set<vector<int>>&ans) {
        if (i == nums.size()) {
            ans.insert(curr);
            return;
        }

               curr.push_back(nums[i]);
        solve(i + 1, nums, curr, ans);

              curr.pop_back();
 
        solve(i + 1, nums, curr, ans);
    
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      set<vector<int>> st;
        vector<int> curr;
        solve(0, nums, curr, st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};