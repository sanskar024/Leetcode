class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0;
        int p=0;
        int q=n-1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans+=nums[p];
                p++;
            }
            else {
                ans-=nums[q];
                q--;
            }
        }

   return ans; }
};