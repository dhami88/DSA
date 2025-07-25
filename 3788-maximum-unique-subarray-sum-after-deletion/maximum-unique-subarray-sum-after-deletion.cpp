class Solution {
public:
    int maxSum(vector<int>& nums) {
       int n=nums.size();
     
        set<int>st;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        if(maxi<0) return maxi;
        for(int i=0;i<n;i++){
           if(nums[i]>0) st.insert(nums[i]);
           else continue;
        }
        int ans=0;
        for(auto it:st){
            ans+=it;
        }
        return ans;
    }
};