class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int reql=n-k;
        int p=0,q=0;
       int curr = 0, ans = INT_MAX;
          int tsum=0;
        for(int x:c)tsum+=x;
        if(reql==0)return tsum;
        while(q<n){
           
            curr+=c[q];
             if(q-p+1>reql){
                curr-=c[p];
                p++;
            }
             if(q-p+1==reql){
                ans=min(ans,curr);
                
            }
           
            q++;
        }
     
        return tsum-ans;
    }
};