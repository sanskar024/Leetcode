class Solution {
public:
bool check(string s){
    for(int i=0;i<s.size();i++){
        s[i]=tolower(s[i]);
    }
    string s1="qwertyuiop";
    string s2="asdfghjkl";
    string s3="zxcvbnm";
    if(s1.find(s[0])!=string::npos){
for(int i=0;i<s.size();i++){
    if(s1.find(s[i])==string::npos)return false;
}
return true;
    }
    else if(s2.find(s[0])!=string::npos){
for(int i=0;i<s.size();i++){
    if(s2.find(s[i])==string::npos)return false;
}return true;
    }
    else {
for(int i=0;i<s.size();i++){
    if(s3.find(s[i])==string::npos)return false;
}return true;
    }
}
    vector<string> findWords(vector<string>& words) {
      vector<string>s;
      for (int i=0;i<words.size();i++){
        if(check(words[i]))s.push_back(words[i]);
      }
      
  
 return s;   }
};