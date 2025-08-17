bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) 
        return a[1] > b[1];  // descending order of 2nd element
    return a[0] < b[0];      // ascending order of 1st element
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        //now apply lis on height
        vector<int>temp;
        for(auto it:envelopes){
            temp.push_back(it[1]);
        }
        vector<int>ans;
        ans.push_back(temp[0]);
        for(int i=1;i<n;i++){
            if(temp[i]>ans.back()){
                ans.push_back(temp[i]);
            }
            else{
            auto it=lower_bound(ans.begin(),ans.end(),temp[i])-ans.begin();
            ans[it]=temp[i];
            }

        }
        return ans.size();
    }
};