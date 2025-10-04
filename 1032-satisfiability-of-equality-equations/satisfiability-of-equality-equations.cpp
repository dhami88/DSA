class disjointset{
    vector<int>parent,size;
    public:
    disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findupar(int node){
        if(node==parent[node]) return node;
        else return parent[node]=findupar(parent[node]);

    }
    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return ;
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
    bool equationsPossible(vector<string>& equations) {
     //dsu chmka ?
     disjointset ds(26);
     for(auto it:equations){
        if(it[1]=='='){
            ds.unionbysize(it[0]-'a',it[3]-'a');
        }
     }
     for(auto it:equations){
         if(it[1]=='!'){
            int u=ds.findupar(it[0]-'a');
            int v=ds.findupar(it[3]-'a');
            if(u==v) return false; 
        }
     }
     return true;
    }
};