class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>biryani(n);
        biryani[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                biryani[i]=biryani[i-1]+1;
            }
            else biryani[i]=1;
        }
        vector<int>legpiece(n);
        legpiece[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                legpiece[i]=legpiece[i+1]+1;
            }
            else legpiece[i]=1;
        }
        int sum=0;
        for(int i=0;i<n;i++){
         sum+= max(biryani[i],legpiece[i]);

        }
        return sum;
    }
};