class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      priority_queue<pair<int, int>> pq;
      for(int i=0;i<score.size();i++){
        pq.push({score[i],i});
      } 
      vector<string>ans(score.size());
      int count=1;
      while(!pq.empty()){
        auto it = pq.top();
            pq.pop();

            if(count==1){
             ans[it.second]="Gold Medal";
             
            }
            else if(count==2){
                 ans[it.second]="Silver Medal";
           
            }
            else if(count==3){
                 ans[it.second]="Bronze Medal";
             
            }
            else {
                ans[it.second]=to_string(count);            
            }
            count++;
        }
      

   return ans; }
};