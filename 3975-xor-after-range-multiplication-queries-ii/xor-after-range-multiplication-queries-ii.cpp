#define ll long long
const int mod = 1e9+7;
ll binexp(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1) res = (res % mod * a % mod) % mod; a = (a % mod * a % mod) % mod; b >>= 1;} return res;}

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int SZ = sqrt(nums.size())+1;
        vector<unordered_map<ll,ll>> Q(nums.size());
        for(auto &q : queries){
            ll l = q[0], r = q[1], k = q[2], v = q[3];
            if(k>=SZ){
                for(int i = l; i<=r; i += k){
                    nums[i] = (nums[i]*v)%mod;
                }
                continue;
            }
            ll inv_v = binexp(v, mod - 2);;
            r += (k-(r-l)%k);
            if(Q[l].find(k)==Q[l].end()) Q[l][k] = v;
            else (Q[l][k] *= v)%=mod;
            if(r<nums.size()){
                if(Q[r].find(k)==Q[r].end()) Q[r][k] = inv_v;
                else (Q[r][k] *= inv_v)%=mod; 
            }
        }
        ll ans = 0;
        for(int i = 0; i<nums.size(); ++i){
            unordered_map<ll,ll> &q = Q[i];
            ll res = nums[i];
            for(auto &p : q){
                (res *= p.second)%=mod;
                if(i+p.first<nums.size()){
                    if(Q[i+p.first].find(p.first)==Q[i+p.first].end()) Q[i+p.first][p.first] = p.second;
                    else (Q[i+p.first][p.first]*=p.second) %= mod;
                }
            }
            q.clear();
            ans ^= res;
        }
        return ans;
    }
};