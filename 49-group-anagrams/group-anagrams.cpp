class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;
        for(auto it:strs){
            string key=it;
            sort(key.begin(),key.end());
            ans[key].push_back(it);            
        }
        vector<vector<string>>flip;
        for(auto it :ans){
            flip.push_back(it.second);
        }
        return flip;
    }
};