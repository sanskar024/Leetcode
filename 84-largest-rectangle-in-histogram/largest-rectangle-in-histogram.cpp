class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        stack<int>st;
        st.push(0);
        left[0]=-1;
        for(int i=1;i<n;i++){
            while(!st.empty()&&h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty())left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }
        // first pass
while(!st.empty()) st.pop();

// now st is empty and ready to use again
 
        right[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
              while(!st.empty()&&h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty())right[i]=n;
            else right[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
           int area=(right[i]-left[i]-1)*(h[i]);
           ans=max(ans,area);
        }
   return ans; }
};