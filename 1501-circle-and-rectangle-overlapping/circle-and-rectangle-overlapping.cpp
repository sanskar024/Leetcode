class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
   int xi;
   int yi;
   if(x1>xc)xi=x1;
   else if(x2<xc)xi=x2;
   else xi=xc;
   if(y1>yc)yi=y1;
   else if(y2<yc)yi=y2;
   else yi=yc;
   int dx = xc - xi;
        int dy = yc - yi;

        return dx * dx + dy * dy <= r * r;
    }
};