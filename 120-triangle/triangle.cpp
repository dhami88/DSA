class Solution {
    int f(int i,int j,vector<vector<int>>& triangle, vector<vector<int>>&dp){
        int n=triangle.size();
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+f(i+1,j,triangle,dp);
        int diag=triangle[i][j]+f(i+1,j+1,triangle,dp);
        return dp[i][j]= min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
      //  vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(0,0,triangle,dp);
        //base case 
        vector<int>front(n,0);
        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>cur(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+front[j];
                int diag=triangle[i][j]+front[j+1];
                cur[j]=min(down,diag);
            }
            front=cur;
        }

        return front[0];
    }
};