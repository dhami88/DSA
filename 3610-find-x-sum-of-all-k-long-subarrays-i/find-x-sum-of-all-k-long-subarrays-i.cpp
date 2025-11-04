class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i+k<=n;i++){
            map<int,int>m;
            for(int j=i;j<=i+k-1;j++){
                m[nums[j]]++;
            }
           //sort by freq and then by value
           vector<pair<int,int>>v(m.begin(),m.end());
           sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(a.second==b.second) return a.first>b.first;
            else return a.second>b.second;
           });
           int sum=0;
            for(int k=0;k<x&&k<v.size();k++){
                sum+= v[k].first*v[k].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};