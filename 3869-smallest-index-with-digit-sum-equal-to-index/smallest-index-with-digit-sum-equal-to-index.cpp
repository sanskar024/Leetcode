class Solution {
public:
bool check(int num,int idx){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    if(sum==idx)return true;
    return false;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(check(nums[i],i))return i;;
        }
           return -1;
    }
 
};