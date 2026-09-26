class Solution {
public:
pair<bool,string> give(string w, vector<vector<string>>& k){
    for(int i=0;i<k.size();i++){
        for(int j=0;j<2;j++){
            if(k[i][0]==w)return {true,k[i][1]};
        }
    }
    return {false,"?"};
}
    string evaluate(string s, vector<vector<string>>& k) {
          unordered_map<string, string> mp;

        for(auto &x : k) {
            mp[x[0]] = x[1];
        }
        string ans="";
        bool flag=false;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                temp="";
 flag=true;

            
            }
        if(flag && s[i] != '(' && s[i] != ')')
    temp += s[i];
            if(s[i]==')'){
                flag=false;
          if(mp.find(temp)!=mp.end()){
            ans+=mp[temp];
          }
           else ans+="?";
            }
            if(!flag && s[i] != ')')ans+=s[i];
            
        }
  return ans;  }
};