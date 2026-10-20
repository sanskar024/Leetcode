class Solution {
public:
    vector<int> constructRectangle(int area) {
        int ans=0;
        for(int i=1;i*i<=area;i++){
            if(area%i==0)ans=i;
        }
    return {area/ans,ans};}
};