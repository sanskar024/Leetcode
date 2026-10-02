class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int>pq;
      for(int n:nums)pq.push(n);
      int count=0;
      int ans=0;
      while(count<k){
        ans=pq.top();
        pq.pop();
        count++;
      }
      return ans;  }
};