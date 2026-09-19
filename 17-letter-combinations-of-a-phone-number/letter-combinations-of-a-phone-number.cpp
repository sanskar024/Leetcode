class Solution {
public:
 vector<string>sec={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
         string curr="";
void solve(int i,string curr,string digit){
if(i==digit.size()){
    ans.push_back(curr);
    return;
}
int currd=digit[i]-'0';

       for(int j=0;j<sec[currd].size();j++){
             curr.push_back(sec[currd][j]);
             solve(i+1,curr,digit);
                  curr.pop_back();
       }
  

return;

        }
    vector<string> letterCombinations(string digits) {
    
        solve(0,curr,digits);
return ans;
    }
};