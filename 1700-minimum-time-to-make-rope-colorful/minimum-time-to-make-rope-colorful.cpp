class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //2 pointer approach
        int l=0;
        int n=colors.size();
        int ans=0;
        for(int r=1;r<n;r++){
          if(colors[l]==colors[r]){
            if(neededTime[l]<neededTime[r]){
                ans+=neededTime[l];
                l=r;
            }
            else {
                ans+=neededTime[r];
              
            }
          } 
          else{
            l=r;
          } 
        }
        return ans;
    }
};