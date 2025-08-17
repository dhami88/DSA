class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long >p1(n),p2(n);
        long long sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=prices[i];
            sum2+=(prices[i]*strategy[i]);
            p1[i]=sum1;
            p2[i]=sum2;
        }
        int j=k-1;
        long long ans=p2[n-1];
        while(j<n){
            int i=(j-k+1);
            int pos1=j-k;
            int pos2=j-k/2;
            long long t = p2[n-1] - (p2[j] - ((pos1 != -1) ? p2[pos1] : 0));
            t += (p1[j] - ((pos2 != -1) ? p1[pos2] : 0));

            ans=max(ans,t);  
            j++;
        }
        return ans;
    }
};