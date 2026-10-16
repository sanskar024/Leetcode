class Solution {
public:
bool check(int d,vector<int> nums, int m, int k){
int count=0,flow=0;
for(int i=0;i<nums.size();i++){
   if(nums[i]<=d){
     
    flow++;
 
  if(flow==k){
    flow=0;
    count++;
 }
   }
 
 else {
    flow=0;
 }
}
if(count>=m)return true;
else return false;

}
    int minDays(vector<int>& nums, int m, int k) {
        int p=*min_element(nums.begin(),nums.end());
        int q=*max_element(nums.begin(),nums.end());
        if ((long long)m * k > nums.size()) return -1;
      
        while(p<q){
            int mid=(p+q)/2;
            if(check(mid,nums,m,k)){
                q=mid;
               
            }
            else p=mid+1;
        }
    return p;}
};