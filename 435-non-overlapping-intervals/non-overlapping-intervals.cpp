class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
          sort(nums.begin(),nums.end(),[](auto &a,auto &b){
            return a[0]<b[0];
          }  );
          int j=0;
          int count=0;
for(int i=1;i<nums.size();i++){
    if(nums[j][1]<=nums[i][0]){
        j=i;
    continue;
    }
    else {
        if(nums[j][1]<nums[i][1]){
            count++;
     
        
           
        }
        else {
            j=i;
            count++;
        }
    }
}
   return count; }
};