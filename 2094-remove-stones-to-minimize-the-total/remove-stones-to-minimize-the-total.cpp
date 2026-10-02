class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       priority_queue<int>pq;
       int ans=0;
       for(int n:piles)pq.push(n);
    
       while(k>0){
        int t=pq.top();
        pq.pop();
 t = t - t / 2;
        pq.push(t);
        k--;
    
       }
       while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
       }
  return ans;  }
};