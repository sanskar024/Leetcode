class Solution {
public:
int solve(vector<int>& nums, int k){
     int ans=0;
       int p=0;int q=0;
       unordered_map<int,int>m;
       while(q<nums.size()){
        m[nums[q]]++;
       
        while(m.size()>k){
            m[nums[p]]--;
            if(m[nums[p]]==0) m.erase(nums[p]);
            p++;
        }
       ans+=q-p+1;
        q++;
       }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
       }
};