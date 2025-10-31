class Solution {
public:
    long long countStableSubarrays(vector<int>& v) {
        int n=v.size();
        vector<long long>pref(n);
        for(int i=0;i<n;i++){
            pref[i]=v[i];
            if(i>0) pref[i]+=pref[i-1];
        }
        long long ans=0;
        map<pair<int,long long>,int>mp;
        for(int i=n-1;i>=0;i--){
            ans+=mp[{v[i],pref[i]+2*v[i]}];
            if(i+1<n) mp[{v[i+1],pref[i+1]}]++;
        }
        return ans;
    }
};