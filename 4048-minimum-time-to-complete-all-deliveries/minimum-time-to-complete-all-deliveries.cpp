class Solution {
    bool isvalid(long long time,vector<int>& d, vector<int>& r){
        long long freetime1= time-(time/r[0]);
        long long freetime2= time-(time/r[1]);
        if(freetime1<d[0] || freetime2<d[1]){
            return false;
        }
        long long freeboth= time-(time/(lcm(r[0],r[1])));
        return freeboth>=(d[0]+d[1]);
    }
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long low=0;
        long long high=1e18;
        long long ans=1e18;
        while(low<=high){
            long long mid= (low+high)/2;
            if(isvalid(mid,d,r)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};