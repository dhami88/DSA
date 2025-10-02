class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       vector<vector<int>>dist(n,vector<int>(m,1e9));
       dist[0][0]=0;
       pq.push({0,{0,0}});
       int dr[]={-1,0,1,0};
       int dc[]={0,1,0,-1};
       while(!pq.empty()){
        int diff=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        pq.pop();
        if(row==n-1&&col==m-1) return diff;
        for(int k=0;k<4;k++){
            int nr=row+dr[k];
            int nc=col+dc[k];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                int neweffort=max(abs(heights[nr][nc]-heights[row][col]),diff);
                if(neweffort<dist[nr][nc]){
                    dist[nr][nc]=neweffort;
                    pq.push({dist[nr][nc],{nr,nc}});
                }

            }
        }

       }
       return 0;
    }
};