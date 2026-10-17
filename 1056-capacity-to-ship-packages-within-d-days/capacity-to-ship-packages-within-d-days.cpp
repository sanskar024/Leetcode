class Solution {
public:
bool check(int d,vector<int>& w, int day){
    int tdays=1;
    int currw=0;
    for(int i=0;i<w.size();i++){
if(currw+w[i]>d){
    currw=w[i];
    tdays++;
}
else currw+=w[i];
    }
    if(tdays<=day)return true;
    else return false;
}
    int shipWithinDays(vector<int>& w, int day) {
      int low = *max_element(w.begin(), w.end());
int high = accumulate(w.begin(), w.end(), 0);
while(low<high){
   int mid = low + (high - low) / 2;
   if(check(mid,w,day)){
    high=mid;
   }
   else low=mid+1;
}
   return low; }
};