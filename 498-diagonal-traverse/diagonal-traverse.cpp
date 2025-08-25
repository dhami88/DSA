class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool flag=true;
        for(auto it:mp){
           if(flag){
            reverse(it.second.begin(),it.second.end());
           }
           for(auto x:it.second){
            ans.push_back(x);
           }
           flag=!flag;
        }
        return ans;
    }
};