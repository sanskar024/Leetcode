class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        priority_queue<int,vector<int>,greater<int>>mh;
          int ans=0;
          mh.push(in[0][1]);
          for(int i=1;i<in.size();i++){
            if(in[i][0]>mh.top()){
                mh.pop();
               
            }
            mh.push(in[i][1]);
          }
  return mh.size();  }
};