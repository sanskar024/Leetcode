class Solution {
public:
    int candy(vector<int>& rat) {
        int ans=0;
        int n=rat.size();
        vector<int>arr(n,1);
        for(int i=1;i<n;i++){
            if(rat[i]>rat[i-1]){
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(rat[i]>rat[i+1]){
                if(arr[i]<=arr[i+1]){
                    arr[i]=arr[i+1]+1;
                }
            }
        }
        for(int x:arr)ans+=x;
   return ans; }
};