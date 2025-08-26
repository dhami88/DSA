class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxdiag=INT_MIN;
        int maxarea=0;
        pair<int,int>idx;
        for(auto it:dimensions){
            int a=it[0];
            int b=it[1];
            int area=((a*a)+(b*b));
            if(area>maxdiag){
                maxdiag=area;
                idx={a,b};
                maxarea=a*b;
            }
            if(area==maxdiag){
              maxarea=max(maxarea,a*b);  
            }
        }
        return maxarea;
    }
};