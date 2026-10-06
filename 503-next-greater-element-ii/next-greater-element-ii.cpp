class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<nums.size();i++){
            for (int k=1;k<n;k++){
                int j = (i + k) % n;
                if(nums[j]>nums[i]){
                    ans[i]=nums[j];
                    break;
                }
                
            }
        }
 return ans;   }
};