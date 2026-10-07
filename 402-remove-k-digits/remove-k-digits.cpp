class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            if(st.empty())st.push(num[i]);
            else{
                while(!st.empty()&&num[i]-'0'<st.top()-'0'&&k>0){
                    st.pop();
                    k--;


                }
                st.push(num[i]);
            }
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        int idx=-1;
reverse(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++){
    if(ans[i]-'0'!=0){
        idx=i;
        break;
    }
}
if(idx==-1)return "0";
string finalans=ans.substr(idx,ans.size()-idx);


   return finalans; }
};