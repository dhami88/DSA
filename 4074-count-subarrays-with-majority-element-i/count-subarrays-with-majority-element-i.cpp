class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            map<int,int>m;
            for(int j=i;j<n;j++){
                m[nums[j]]++;
                if(m[target]>(j-i+1)/2) cnt++;
            }
          
        }
        return cnt;
    }
};