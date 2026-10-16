class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
  int n=nums.size();
        
        if(n%k!=0)return false;
        unordered_map<int,int>mp;
        for(int x:nums)mp[x]++;
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        bool toadd=true;
        while(!pq.empty()){
            vector<pair<int,int>>temp;
            
            int first=pq.top().first;
            int freq=pq.top().second;
            pq.pop();
             if (freq > 1) {
                temp.push_back({first, freq - 1});
            }

           int prev=first;
            for(int i=1;i<k;i++){
if(pq.empty() ||pq.top().first!=prev+1)return false;
else {
    auto ele=pq.top();
    pq.pop();
    if(ele.second-1>0){
        temp.push_back({ele.first,ele.second-1});
    }
    prev=ele.first;
}

            }
        for(int i=0;i<temp.size();i++){
            pq.push(temp[i]);
        }
        
        }
  return true;
    }
};