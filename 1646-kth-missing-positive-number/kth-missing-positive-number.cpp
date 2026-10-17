class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>mis;
       int i=1;
      int j=0;
      while(j<arr.size()){
        if(arr[j]==i)j++;
        else {
            mis.push_back(i);
           } i++;
      }
        if(mis.size()<k)return arr[arr.size()-1]+k-mis.size();
   return mis[k-1]; }
};