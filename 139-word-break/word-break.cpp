class Solution {
    bool solve(int ind,string s, unordered_set<string>&st,vector<int>&dp){
        if(ind==s.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int l=1;l<=s.size();l++){
            string w=s.substr(ind,l);
            if(st.find(w)!=st.end()&&solve(ind+l,s,st,dp)){
                return dp[ind]=true;
            }

        }
        return dp[ind]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string>st(wordDict.begin(),wordDict.end());
       vector<int>dp(s.size(),-1);
       return solve(0,s,st,dp); 
    }
};