class Solution {
public:
unordered_set<int>seen;
bool solve(int n){
    if(n==1)return true;
    if(seen.count(n))return false;
    else seen.insert(n);
    int next=0;
    while(n>0){
        int rem=n%10;
        next+=rem*rem;
        n/=10;
    }
   return  solve(next);

}
    bool isHappy(int n) {
        return solve(n);
    }
};