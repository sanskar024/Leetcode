class Solution {
public:
    int minRotations(string s) {
        
        int curr=0;
        int ans=0;
        for(char c:s){
          int d=c-'0';
          int wrapped=0;
          if(curr>d){
            wrapped=10-curr+d;
          }
          else wrapped=10-d+curr;
          ans+=min(abs(d-curr),wrapped);
          curr=d;
        }
   return ans; }
};