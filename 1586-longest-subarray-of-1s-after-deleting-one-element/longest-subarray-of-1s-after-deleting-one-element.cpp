class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        //if(n==1&&nums[0]==0) return 0;
       map<int,int>m;
       //sliding window with at most 1 zero
        int l=0;
        int maxi=0;
        for(int r=0;r<n;r++){
            m[nums[r]]++;
            while(!m.empty()&&m[0]>1){
                m[nums[l]]--;
                l++;
            }
            maxi=max(maxi,r-l);
        }
        return maxi;
    }
};