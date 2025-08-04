class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        map<int,int>m;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            m[fruits[r]]++;
            while(m.size()>2){
                m[fruits[l]]--;            
            if(m[fruits[l]]==0) {
                m.erase(fruits[l]);
            }
                l++;
            
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};