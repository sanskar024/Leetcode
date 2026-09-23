class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
int maxl=-1;
int tsum=0;
for(int s:nums){
    tsum+=s;
}
int sum=tsum-x;
if(sum<0)return -1;
int p=0;
int q=0;
int currsum=0;
while(q!=nums.size()){
    currsum+=nums[q];
    while(currsum>sum){
        currsum-=nums[p];
        p++;
    }
    if(currsum==sum){
        maxl=max(maxl,q-p+1);
    }
    q++;
}

return maxl==-1?-1:nums.size()-maxl;    }
};