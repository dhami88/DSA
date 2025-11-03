class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        //har ek house k liye nearest heater find kro
        int ans=0;
       for(auto it:houses){
       auto a = lower_bound(heaters.begin(),heaters.end(),it);//index
       int leftsmaller= (a==heaters.end())?INT_MAX:abs(it-*a);
       int rightsmaller=(a==heaters.begin())?INT_MAX:abs(it-*(a-1));
        ans=max(ans,min(leftsmaller,rightsmaller));
       }
       return ans;
    }
};