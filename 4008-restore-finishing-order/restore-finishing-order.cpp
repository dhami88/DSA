class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=friends.size();
        vector<int>ans;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(friends[i]);
        }
        int m=order.size();
        for(int i=0;i<m;i++){
            if(st.count(order[i])){
                ans.push_back(order[i]);
            }
           // else continue;
        }
         return ans;
    }
};