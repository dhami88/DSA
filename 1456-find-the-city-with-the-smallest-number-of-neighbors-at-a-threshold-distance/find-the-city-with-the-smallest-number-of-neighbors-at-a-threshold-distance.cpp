class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
         dist[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        
        int city=-1;
        int maxc=n;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold){
                cnt++;
            }
            }
            if(maxc>=cnt){
                maxc=cnt;
                city=i;
            }
        }
        return city;
    }
};