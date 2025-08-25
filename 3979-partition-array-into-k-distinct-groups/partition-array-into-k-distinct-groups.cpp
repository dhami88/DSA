class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        int a=n/k;
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>a) return false;           
        }
        return true;
    }
};