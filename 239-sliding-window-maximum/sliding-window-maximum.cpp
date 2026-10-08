class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result;
deque<int>deq;
for(int i=0;i<n;i++){
     while(!deq.empty()&&deq.front()<=i-k){
        deq.pop_front();
    }
    while(!deq.empty()&&nums[deq.back()]<nums[i]){
        deq.pop_back();
    }
   
    deq.push_back(i);
    if(i+1>=k)
    result.push_back(nums[deq.front()]);
}
    return result;}
};