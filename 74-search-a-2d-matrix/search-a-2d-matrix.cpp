class Solution {
public:
 bool solve(int i,vector<vector<int>>& mat, int target){
    int p=0;
    int q=mat[0].size()-1;
     while(p<=q){
                int mid=(p+q)/2;
                if(mat[i][mid]==target)return true;
             else if(target>mat[i][mid])p=mid+1;
             else q=mid-1;
            }
            return false;
 }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size()-1;
       int l=0;
       int h=n-1;
     
       while(l<=h){
        int mid=(l+h)/2;
if(mat[mid][0]<=target&&target<=mat[mid][m]){
return solve(mid,mat,target);
}
else if(mat[mid][0]>target) {
    h=mid-1;
}
else {
    l=mid+1;
}
       }
      
   return  false;}
};