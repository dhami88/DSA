
long long hours(vector<int>v,int mid){
    long long hi=0;
    for(int i=0;i<v.size();i++){
     hi+=ceil((double)v[i]/(double)mid);
    }
    return hi;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        long long low=1;
    long long high=*max_element(v.begin(),v.end());
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(hours(v,mid)<=h) high=mid-1;
        else low=mid+1;
    }
    return low;
    }
};