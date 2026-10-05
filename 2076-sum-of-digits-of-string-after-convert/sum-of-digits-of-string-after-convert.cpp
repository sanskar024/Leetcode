class Solution {
public:
int solve(int num,int k){
   if(k==0)return num;
   int next=0;
   while(num>0){
    next+=num%10;
    num=num/10;
   }
   return solve(next,k-1);
}
    int getLucky(string s, int k) {
        string ans="";
        for(char c:s){
int val=c-'a'+1;
ans+=to_string(val);
        }
        int x=0;
        for(char c:ans){
           
            x+=c-'0';
        } 
        return solve(x,k-1);
    }
};