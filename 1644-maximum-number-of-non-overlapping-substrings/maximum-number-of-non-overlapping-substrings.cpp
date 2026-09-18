class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>st(26,-1);
          vector<int>en(26,-1);
          vector<string>result;
          for(int i=0;i<n;i++){
            if(st[s[i]-'a']==-1)st[s[i]-'a']=i;
            en[s[i]-'a']=i;
          }
          vector<bool>valid(26,true);
          for(int i=0;i<26;i++){
if(st[i]==-1)continue;
for(int idx=st[i];idx<=en[i];idx++){
    if(st[s[idx]-'a']<st[i]){
        valid[i]=false;
        break;
    }
    else if(en[s[idx]-'a']>en[i]){
        en[i]=en[s[idx]-'a'];
    }
}
 }
 int lasttaken=INT_MAX;
          for(int i=n-1;i>=0;i--){
    if(valid[s[i]-'a']==false)continue;
    if(st[s[i]-'a']==i&&lasttaken>en[s[i]-'a']){
        string curr="";
        for(int idx=i;idx<=en[s[i]-'a'];idx++){
            curr+=s[idx];
        }
        result.push_back(curr);
        lasttaken=st[s[i]-'a'];
        
    }
}
    return result;}
};