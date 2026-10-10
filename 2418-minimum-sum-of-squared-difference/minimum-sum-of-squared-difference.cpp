class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<long long> diff(n);
   vector<long long>count(1e5+1,0);
         for (int i = 0; i < n; i++) {
             diff[i] = abs(nums1[i] - nums2[i]);
             count[diff[i]]++;
                       }
       long long k = 1LL * k1 + k2;
       
    
       for(int i=1e5;i>=1;i--){
       long long reduce=min(k,count[i]);
        if(count[i]>0&&k>0){
            k-=reduce;
            count[i-1]+=reduce;
            count[i]-=reduce;
        }
       }
        
long long ans=0;
       for(int i=0;i<count.size();i++){
       
       ans+=1LL*i*i*count[i];
       }

   return ans; }
};