class Solution {
public:
    int minCost(int n) {
    vector<int>dp(501,0);
    dp[1]=0;
    for(int i=2;i<=500;i++){
        dp[i]=dp[i-1]+i-1;
    }
    return dp[n];
    }
};