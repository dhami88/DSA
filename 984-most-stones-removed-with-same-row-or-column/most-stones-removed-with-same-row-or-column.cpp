class Solution {
    void dfs(int index,vector<vector<int>>& stones,vector<int>&vis){
        vis[index]=1;
       for(int i=0;i<stones.size();i++){
        int r=stones[index][0];
        int c=stones[index][1];
        if(vis[i]==0&&( stones[i][0]==r||stones[i][1]==c)){
            dfs(i,stones,vis);
        }
       }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,stones,vis);
                ans++;
            }
        }
        return n-ans;
    }
};