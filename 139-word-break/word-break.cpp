class Solution {
    public:
     unordered_set<string>st;
    bool solve (int ind,string &s,vector<int>&dp){
    int n=s.size();
    if(ind==n) return true;
    if(dp[ind]!=-1) return dp[ind];
    for(int l=1;l<=n;l++){
        string temp=s.substr(ind,l);
        if(st.find(temp)!=st.end()&&solve(ind+l,s,dp)){
            return dp[ind]= true;
        }
    }
    return dp[ind]=false;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        st.insert(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int>dp(n,-1);
       return solve (0,s,dp);
    }
};