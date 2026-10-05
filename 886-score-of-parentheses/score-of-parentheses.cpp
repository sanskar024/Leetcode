class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        vector<int>ans;
       int score=0;
        for(int i=0;i<n;i++){
if(s[i]=='('){
    ans.push_back(score);
    score=0;
}
else if(s[i]==')'&&s[i-1]=='('){
    score=ans.back()+1;
ans.pop_back();

}else {

   score = ans.back()+ score*2;
ans.pop_back();

}
        }
 return score;  }
};