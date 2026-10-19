class Solution {
public:
bool check(int sum,vector<int>& nums, int k){
    int total=1;
    int currsum=0;
    for(int i=0;i<nums.size();i++){
       if( currsum+nums[i]>sum){
        total++;
        currsum=nums[i];

       }else currsum+=nums[i];
    }
    return total<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<high){
            int mid=(low+high)/2;
            if(check(mid,nums,k)){
                high=mid;
            }else {
                low=mid+1;
            }
        }
    return low;}
};