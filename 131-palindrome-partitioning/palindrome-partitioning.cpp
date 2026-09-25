class Solution {
public:
bool ispal(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}
    vector<vector<string>>ans;
void solve(int i,string s,string temp,vector<string>&path){
    if(i==s.size()){
        ans.push_back(path);
        return ;

    }
    for(int j=i;j<s.size();j++){
        temp+=s[j];
 if(ispal(temp)){
 path.push_back(temp);
 solve(j+1,s,"",path);
 path.pop_back();
    }
    }
   

}
    vector<vector<string>> partition(string s) {
        int n =s.size();
        string temp="";
        vector<string>path;
        solve(0,s,temp,path);
        
   return ans; }

};