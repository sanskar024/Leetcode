class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int currnum=9;
        while(sum!=0&&num>0){
            if(currnum>sum){
                currnum-=1;
            }
            else {
sum-=currnum;
num-=1;
ans+=to_string(currnum);
currnum=9;
            }
        }
        while(num>0&&sum==0){
            ans+='0';
            num--;
        }
        if(sum>0&&num==0)return "";
       
return ans;   }
};