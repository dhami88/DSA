class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
      int n=bulbs.size();
      map<int,int>m;
      for(auto it:bulbs){
        m[it]++;
      } 
      for(auto i : m){
        if(i.second%2==1) ans.push_back(i.first);
      } 
      return ans;
    }
};