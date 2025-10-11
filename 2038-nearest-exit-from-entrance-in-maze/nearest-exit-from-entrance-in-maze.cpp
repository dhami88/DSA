class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({{entrance[0],entrance[1]},0});
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            auto node=q.front();
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nr=r+delr[k];
                int nc=c+delc[k];
               if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&maze[nr][nc]=='.'){
                 if (nr == 0 || nc == 0 || nr == n-1 || nc == m-1) {
                        return dist + 1;
                    }
                    q.push({{nr,nc},1+dist});
                    vis[nr][nc]=1;
                }
                  
            }

        }
        return -1;
    }
};