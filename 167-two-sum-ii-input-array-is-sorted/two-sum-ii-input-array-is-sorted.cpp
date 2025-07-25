class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //int n=numbers.size();
        int n=nums.size();
      map<int,int>m;
      vector<int>ans;
      for(int i=0;i<n;i++){
        int rem=target-nums[i];
        if(m.find(rem)!=m.end()){
            ans.push_back(i+1);
            ans.push_back(m[rem]+1);
        }
        m[nums[i]]=i;
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};