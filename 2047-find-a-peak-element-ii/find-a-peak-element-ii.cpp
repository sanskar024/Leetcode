class Solution {
public:
pair<int,int> solve(int col,vector<vector<int>>& mat){
    int ans=-1,row=0;
     int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            if(mat[i][col]>ans){
                ans=mat[i][col];
                row=i;
            }
        }
        return {ans,row};
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            auto max_ele=solve(mid,mat);
            int ele=max_ele.first;
            int idx=max_ele.second;
            int left=(mid==0)?-1:mat[idx][mid-1];
            int right=(mid==n-1)?-1:mat[idx][mid+1];
           
            if(mat[idx][mid]>left&&mat[idx][mid]>right)return {idx,mid};
            else if(mat[idx][mid]<left){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
 return {-1,-1};   }
};