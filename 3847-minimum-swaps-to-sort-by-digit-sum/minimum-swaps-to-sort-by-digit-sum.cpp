class Solution {
public:
int convert(int n){
    int dsum=0;
    while(n>0){
dsum+=n%10;
n/=10;
    }
    return dsum;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(nums);
       
      sort(arr.begin(), arr.end(), [&](auto& a, auto& b) {
        int x=convert(a);
        int y=convert(b);
        if(x!=y)
    return x < y;
   return a<b;
});
unordered_map<int,int>mp;
for(int i=0;i<n;i++){
    mp[nums[i]]=i;
}
int ans=0;
for(int i=0;i<n;i++){
    int idx=mp[arr[i]];
  if(nums[i]!=arr[i]) {
  mp[nums[i]]=idx;
  mp[nums[idx]]=i;
   swap(nums[i],nums[idx]);
  ans++;}
}


  return ans;  }
};