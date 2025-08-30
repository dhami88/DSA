class Solution {
    int f(int ind1,int ind2,vector<vector<int>>&dp,vector<int>& nums1, vector<int>& nums2){
        if(ind1<0||ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(nums1[ind1]==nums2[ind2]) return 1+f(ind1-1,ind2-1,dp,nums1,nums2);
        return dp[ind1][ind2]=max(f(ind1-1,ind2,dp,nums1,nums2),f(ind1,ind2-1,dp,nums1,nums2));

    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,nums1,nums2);
    }
};