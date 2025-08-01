class Solution {
public:
    vector<vector<int>> generate(int row) {
        vector<vector<int>>final;
       for(int i=1;i<=row;i++){
           vector<int>ansrow;
           long long ans =1;
           ansrow.push_back(1);
           for(int col=1;col<i;col++){
            ans=ans*(i-col);
            ans=ans/col;
            ansrow.push_back(ans);
           }
           final.push_back(ansrow);
       }
      return final;
        
    }
};