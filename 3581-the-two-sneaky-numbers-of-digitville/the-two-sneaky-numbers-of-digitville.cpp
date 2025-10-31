class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        vector<int>ans;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};