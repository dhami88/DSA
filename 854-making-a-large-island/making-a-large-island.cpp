class disjointset{
  
    public:
    vector<int>parent,size;
    disjointset(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findupar(parent[node]);
    }
    void unionbysize(int u,int v){
         int ulp_u=findupar(u);
    int ulp_v=findupar(v);
    if(ulp_u==ulp_v) return;
    if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];

    }
    else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }

    }

};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
       disjointset ds(n*n);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0) continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==1){
                    ds.unionbysize((i*n)+j,(nr*n)+nc);
                }
            }

        }
       }
       int mx=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1) continue;
            set<int>s;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==1){
                    s.insert(ds.findupar((nr*n)+nc));
                }
            }
            int total=0;
                for(auto it:s){
                   total+=ds.size[it];
            }
            mx=max(mx,total+1);
        }
       }
       for(int i=0;i<n*n;i++){
        mx=max(mx,ds.size[ds.findupar(i)]);
     }
    return mx;
    }
};