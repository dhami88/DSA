class disjointset{
    vector<int>size,parent;
    public:
    disjointset(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findupar(parent[node]);
    }

    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]++;
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]++;
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=0;
        int maxc=0;
        for(auto it:stones){
             maxr=max(it[0],maxr);
            maxc=max(it[1],maxc);
        }
        disjointset ds(maxr+maxc+1);
        unordered_map<int,int>m;
        for(auto it:stones){
            int a=it[0];
            int b=it[1]+maxr+1;
           ds.unionbysize(a,b);
           m[a]=1;
           m[b]=1;

        }
        int cnt=0;
        for(auto it:m){
            if(ds.findupar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};