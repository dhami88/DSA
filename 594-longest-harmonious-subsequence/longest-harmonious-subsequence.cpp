class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int a=nums[i];
            if(m.find(a+1)!=m.end()){
                maxi=max(maxi,m[a]+m[a+1]);
            }
            else continue;
        }
        return maxi;
    }
};