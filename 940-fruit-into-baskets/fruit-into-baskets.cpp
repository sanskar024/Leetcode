class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int p=0;
        int q=0;
        unordered_map<int,int>m;
        while(q<fruits.size()){
            m[fruits[q]]++;
            while(m.size()>2){
                m[fruits[p]]--;
                if(m[fruits[p]]==0)m.erase(fruits[p]);
                p++;
            }
            ans=max(ans,q-p+1);
            q++;
        }
   return ans; }
};