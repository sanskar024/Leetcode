class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum)return "";
        string ans="";
        int nine=sum/9;
        int rest=sum%9;
        while(nine>0){
            ans+='9';
            nine--;
            num--;
        }
      if(num>0){
        num--;
        ans+=to_string(rest);}
  
        while(num>0){
            ans+='0';
            num--;
        }
    return ans;}
};