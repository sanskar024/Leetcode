class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int p=1;
        int q=*max_element(nums.begin(),nums.end());
       
        while(p<q){
            int mid=(p+q)/2;
   int sum=0;
   for(int x:nums){
      sum += (x + mid - 1) / mid;
   }
   
   if(sum>threshold){
    p=mid+1;
   }
   else q=mid;
        }
 return p;   }
};