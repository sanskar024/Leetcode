class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0,j=0,ans=INT_MAX;
        int n=arr.size();
        vector<int>lastmax(n,0);
        int currsum=0;
        while(j<n){
            currsum+=arr[j];
       
            while(currsum>target){
                currsum-=arr[i];
                i++;
            }
            if(currsum==target){
                int l=j-i+1;
              if(j==0) lastmax[j] =l;
              else {
                if(lastmax[j-1]==0){
                    lastmax[j]=l;
                }else lastmax[j]=min(lastmax[j-1],l);
              }


if (i > 0 && lastmax[i-1] != 0)
    ans = min(ans, l + lastmax[i-1]);
            }
            else {
                  if (j > 0)lastmax[j]=lastmax[j-1];
            }
                 j++;
        }
   return ans==INT_MAX?-1:ans; }
};