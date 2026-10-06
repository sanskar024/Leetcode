class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<nums.size();i++){
            for (int k=i+1;k<n+i;k++){
               int j = k % n;
                if(nums[j]>nums[i]){
                    ans[i]=nums[j];
                    break;
                }
                
            }
        }
 return ans;   }
};