class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int u=0,l=0;
        bool first=false;
        if(isupper(word[0]))first=true;
        for(char c:word){
            if(isupper(c))u++;
            else l++;
        }
        if(u==n||l==n)return true;
        else if(first&&u==1)return true;
        
   return false; }
};