class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
       unordered_map<int,vector<int>>temp1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               temp1[i-j].push_back(grid[i][j]);
            }
        }        
        for(auto &it:temp1){
            if(it.first>=0){
                sort(it.second.begin(),it.second.end());
            }
            else sort(it.second.rbegin(),it.second.rend());
        }
        //reconstruction
         vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int key=i-j;
                ans[i][j]=temp1[key].back();
                temp1[key].pop_back();
            }
        }
        return ans;
    }
};