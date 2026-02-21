class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        map<int,int>freq;
        for(auto it:m){
            freq[it.second]++;
        }
        for(auto it:nums){
            if(freq[m[it]]==1) return it;
        }
        return -1;
    }
};