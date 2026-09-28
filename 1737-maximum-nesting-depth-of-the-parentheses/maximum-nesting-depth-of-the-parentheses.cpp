class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0;
        int curr=0;
        for(int i=0;i<s.size();i++){
if(s[i]=='('){
      curr++;
    ans=max(ans,curr);
  
    st.push('(');
}
else if(s[i]==')'){
    if(!st.empty()){
        st.pop();
        curr--;

    }
}
else continue;
        }
  return ans;  }
};