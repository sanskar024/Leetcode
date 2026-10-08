class Solution {
public:
int ans=0;
void solve(vector<int>arr){
    int n=arr.size();
    vector<int>left(n,0);
      vector<int>right(n,0);
      stack<int>st;
      st.push(0);
left[0] = -1;
      for(int i=1;i<n;i++){
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
         }
         if(st.empty())left[i]=-1;
         else left[i]=st.top();
         st.push(i);
      }
      while(!st.empty()){
        st.pop();
      }
      st.push(n-1);
      right[n-1]=n;
      for(int i=n-2;i>=0;i--){
         while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
         }
         if(st.empty())right[i]=n;
         else right[i]=st.top();
         st.push(i);
      }
      for(int i=0;i<n;i++){
        int area=(right[i]-left[i]-1)*arr[i];
        ans=max(ans,area);
      }

}
    int maximalRectangle(vector<vector<char>>& mat) {
       int rows = mat.size();
int cols = mat[0].size();
if(mat.empty()) return 0;
       vector<vector<int>> v(rows, vector<int>(cols, 0));
       for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {

        if(i > 0){
            if(mat[i][j]=='0')v[i][j]=0;
          else  v[i][j] = v[i-1][j] + mat[i][j]-'0';
            }
        else
            v[i][j] = mat[i][j]-'0';
    }
}

for(int i=0;i<rows;i++){
    vector<int>temp;
    for(int j=0;j<cols;j++){
temp.push_back(v[i][j]);
    }
    solve(temp);
}
  return ans;  }
};